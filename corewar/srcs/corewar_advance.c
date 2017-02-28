/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_advance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:44:12 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/25 16:19:39 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_f_cw_op	get_op_func(unsigned char op_code)
{
	static t_f_cw_op	tab[17] = { &apply_nothing,
		&apply_live,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		&apply_zjmp,
		NULL, NULL,
		&apply_fork };

	if (op_code >= 17 || tab[op_code] == NULL)
		return (tab[0]);
	return (tab[op_code]);
}

static int			apply_op(t_corewar *corewar, t_process *process)
{
	int				ret;
	t_f_cw_op		func;

	func = get_op_func(process->current_op->op_code);
	if ((ret = (*func)(corewar, process)) < 0)
		return (ret);
	corewar_update_process(corewar, process);
	return (0);
}

int					corewar_advance(t_corewar *corewar)
{
	t_list_it		it;
	t_process		*proc;
	int				ret;

	if (corewar == NULL)
		return (0);
	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		proc = (t_process *)(ft_list_it_get(corewar->process, it));
		if (proc->to_wait > 0)
			--(proc->to_wait);
		else
		{
			if ((ret = apply_op(corewar, proc)) < 0)
				return (ret);
		}
		ft_list_it_inc(&it);
	}
	++(corewar->cycle);
	if (corewar->cycle - corewar->last_check >= corewar->cycles_to_die)
		corewar_check(corewar);
	return (0);
}
