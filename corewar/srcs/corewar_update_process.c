/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_update_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:29:18 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:52:21 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_update_process(t_corewar *corewar,
		t_process *process)
{
	process->current_op = get_op_by_code(corewar->memory[process->pc]);
	process->to_wait = process->current_op->cycles;
}
