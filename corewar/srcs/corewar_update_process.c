/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_update_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:28:17 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:28:18 by etrobert         ###   ########.fr       */
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

void				corewar_update_process(const t_corewar *corewar,
		t_process *process)
{
	unsigned char	op_code;

	corewar_read(corewar, (t_memory){&op_code, sizeof(op_code)}, process->pc);
	process->current_op = get_op_by_code(op_code);
	corewar_update_process_to_wait(process);
	process->new_instr = false;
}
