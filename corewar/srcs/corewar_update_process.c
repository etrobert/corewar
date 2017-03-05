/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_update_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:29:18 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/05 17:32:23 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_update_process(t_corewar *corewar,
		t_process *process)
{
	unsigned char	op_code;

	ft_cbuff_read(corewar->memory, &op_code,
			process->pc, sizeof(unsigned char));
	process->current_op = get_op_by_code(op_code);
	process->to_wait = process->current_op->cycles;
}
