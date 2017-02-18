/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:48:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/18 21:29:57 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				apply_live(t_corewar *corewar, t_process *process)
{
	unsigned int	id;	

	ft_cbuff_read(corewar->memory, &id, process->pc + 1, sizeof(unsigned int));
	id = ft_uint32_big_endian(id);
//	id = ft_uint32_big_endian(
//				*(unsigned int *)(corewar->memory + process->pc + 1));
	
	//TODELL
	int j = 0x42424242;
	ft_cbuff_write(corewar->memory, &j, corewar->memory->size - 1, sizeof(int));

	ft_printf("un processus dit que le joueur %u(?) est en vie\n", id);
	corewar_update_process_pc(corewar, process, 5);
}
