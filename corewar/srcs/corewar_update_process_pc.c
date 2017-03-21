/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_update_process_pc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:31:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:19:36 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_update_process_pc(const t_corewar *corewar,
		t_process *proc, int value)
{
	unsigned int	new_pc;

	(void)corewar;
	if (proc == NULL)
		return ;
	new_pc = (proc->pc + value) % MEM_SIZE;
	if ((corewar->verbosity & CW_VB_PC_MOV) != 0)
		corewar_print_log(corewar, "Process %u moved from %4u to %4u\n",
				proc->proc_id, proc->pc, new_pc);
	proc->pc = new_pc;
}
