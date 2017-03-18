/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:35:48 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/16 19:32:25 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_zjmp(t_corewar *corewar, t_process *process)
{
	short			value;

	if (process->carry)
	{
		corewar_read(corewar, (t_memory){&value, sizeof(value)},
				process->pc + 1);
		value = ft_short16_big_endian(value);
		corewar_print_op(corewar, process, "zjmp %hd\n", value);
		corewar_update_process_pc(corewar, process, (int)(value) % IDX_MOD);
	}
	else
		corewar_update_process_pc(corewar, process, 3);
	return (0);
}
