/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:35:48 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 21:09:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_zjmp(t_corewar *corewar, t_process *process)
{
	short			value;

	if (process->carry)
	{
		ft_cbuff_read(corewar->memory, &value, process->pc + 1, sizeof(short));
		value = ft_short16_big_endian(value);
		//value = ft_short16_big_endian(*(short*)(corewar->memory + process->pc + 1));
		ft_printf("zjmp a %d\n", (int)(value));
		corewar_update_process_pc(corewar, process, (int)(value));
	}
	else
		corewar_update_process_pc(corewar, process, 1);
	return (0);
}
