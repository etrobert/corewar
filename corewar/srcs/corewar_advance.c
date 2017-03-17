/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_advance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:44:12 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/15 17:50:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//todell
#include "print.h"

static t_f_cw_op	get_op_func(unsigned char op_code)
{
	static t_f_cw_op	tab[17] = { &apply_nothing, &apply_live, &apply_ld,
		&apply_st, &apply_add, NULL, &apply_and, &apply_or, &apply_xor,
		&apply_zjmp,
		NULL, &apply_sti,
		&apply_fork,
		&apply_lld, NULL, NULL,
		&apply_aff };

	if (op_code >= 17 || tab[op_code] == NULL)
		return (tab[0]);
	return (tab[op_code]);
}

static int			apply_op(t_corewar *corewar, t_process *process)
{
	int				ret;
	t_f_cw_op		func;

	//ft_dprintf(corewar->fd, "looking to apply %d\n",  process->current_op->op_code);
	func = get_op_func(process->current_op->op_code);
	if ((ret = (*func)(corewar, process)) < 0)
		return (ret);
//	corewar_update_process(corewar, process);
	process->new_instr = true;
	return (0);
}

static int			corewar_advance_one(t_corewar *corewar, t_process *proc)
{
	int				ret;

	//ft_dprintf(corewar->fd, "advancing ");
	//print_process_fd(corewar->fd, proc);
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
