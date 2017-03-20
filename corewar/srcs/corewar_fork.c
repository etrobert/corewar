/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:20:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 16:53:22 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_fork(t_corewar *corewar,
		t_process *parent, t_reg_type pc)
{
	t_process		*new_proc;
	int				ret;

	if (corewar == NULL || parent == NULL)
		return (0);
	if ((new_proc = process_cpy(parent)) == NULL)
		return (-1);
	new_proc->pc = pc;
	new_proc->new_instr = true;
	if ((ret = corewar_add_process(corewar, new_proc)) < 0)
	{
		process_delete(new_proc);
		return (ret);
	}
	return (0);
}
