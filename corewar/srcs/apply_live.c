/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:48:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/15 17:26:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_live(t_corewar *corewar, t_process *process)
{
	unsigned int	id;

	ft_cbuff_read(corewar->memory, &id, process->pc + 1, sizeof(unsigned int));
	id = ft_uint32_big_endian(id);
	corewar_print_op(corewar, process, "live %u\n", id);
	corewar_print_live(corewar, id);
	++(corewar->nbr_live);
	//corewar->last_living_champ = id;
	process->last_live = corewar->cycle;
	corewar_update_process_pc(corewar, process, 5);
	return (0);
}
