/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_advance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:44:12 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 10:39:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_f_cw_op	get_op_func(unsigned char op_code)
{
	static t_f_cw_op	tab[17] = { &apply_nothing, &apply_live, &apply_ld,
		&apply_st, &apply_add, &apply_sub, &apply_and, &apply_or, &apply_xor,
		&apply_zjmp, &apply_ldi, &apply_sti, &apply_fork,
		&apply_lld, &apply_lldi, &apply_lfork, &apply_aff };

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
	process->new_instr = true;
	return (0);
}

static int			corewar_advance_one(t_corewar *corewar, t_process *proc)
{
	int				ret;

	if (proc->new_instr)
		corewar_update_process(corewar, proc);
	if (proc->to_wait > 0)
		--(proc->to_wait);
	else
	{
		if ((ret = apply_op(corewar, proc)) < 0)
			return (ret);
	}
	return (0);
}

int					corewar_advance(t_corewar *corewar)
{
	t_list_it		it;
	int				ret;

	if (corewar == NULL)
		return (0);
	corewar_print_cycle(corewar);
	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		if ((ret = corewar_advance_one(corewar, (t_process *)
						(ft_list_it_get(corewar->process, it)))) != 0)
			return (ret);
		ft_list_it_inc(&it);
	}
	++(corewar->cycle);
	if (corewar->cycle - corewar->last_check >= corewar->cycles_to_die)
		corewar_check(corewar);
	return (0);
}
