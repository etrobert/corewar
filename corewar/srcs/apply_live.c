/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:48:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 13:31:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_live(t_corewar *corewar, t_process *process)
{
	unsigned int	id;

	ft_cbuff_read(corewar->memory, &id, process->pc + 1, sizeof(unsigned int));
	id = ft_uint32_big_endian(id);
	ft_printf("un processus dit que le joueur %u(?) est en vie\n", id);
	++(corewar->nbr_live);
	process->last_live = corewar->cycle;
	corewar_update_process_pc(corewar, process, 5);
	return (0);
}
