/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_advance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:44:12 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:49:44 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			apply_op(t_corewar *corewar, t_process *process)
{
	if (process->current_op->op_code == 1)
		apply_live(corewar, process);
	else
		apply_nothing(corewar, process);
	//APpliquer l'operation
	//deplacer a linstruction suivante et set le to_wait
	corewar_update_process(corewar, process);
}

void				corewar_advance(t_corewar *corewar)
{
	t_list_it		it;
	t_process		*proc;

	if (corewar == NULL)
		return ;
	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		proc = (t_process *)(ft_list_it_get(corewar->process, it));
		if (proc->to_wait > 0)
			--proc->to_wait;
		else
			apply_op(corewar, proc);
		ft_list_it_inc(&it);
	}
}
