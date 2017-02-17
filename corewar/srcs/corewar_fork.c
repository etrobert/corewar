/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:20:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:44:56 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_fork(t_corewar *corewar,
		t_process *parent, t_reg_type pc)
{
	t_process		*new_proc;

	if (corewar == NULL || parent == NULL)
		return (0);
	if ((new_proc = process_cpy(parent)) == NULL)
		return (-1);
	new_proc->pc = pc;
	//Carry stays the same ?
	corewar_update_process(corewar, new_proc);
	if (ft_list_push_front(corewar->process, new_proc) == -1)
	{
		process_delete(new_proc);
		return (-1);
	}
	return (0);
}
