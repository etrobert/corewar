/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_update_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:29:18 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/15 18:59:04 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			corewar_update_process_to_wait(t_process *process)
{
	if (process->current_op->cycles == 0)
		process->to_wait = 0;
	else
		process->to_wait = process->current_op->cycles - 1;
}

void				corewar_update_process(t_corewar *corewar,
		t_process *process)
{
	unsigned char	op_code;

	ft_cbuff_read(corewar->memory, &op_code,
			process->pc, sizeof(unsigned char));
//	corewar_print_log(corewar, "updating a process with op_code %d\n", op_code);
	process->current_op = get_op_by_code(op_code);
	corewar_update_process_to_wait(process);

	process->new_instr = false;
}
