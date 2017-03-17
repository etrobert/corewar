/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:48:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 19:04:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_live(t_corewar *corewar, t_process *process)
{
	unsigned int	id;

	corewar_read(corewar, (t_memory){&id, sizeof(id)}, process->pc + 1);
	id = ft_uint32_big_endian(id);
	corewar_print_op(corewar, process, "live %u\n", id);
	corewar_print_live(corewar, id);
	++(corewar->nbr_live);
	corewar->last_living_champ = id;
	process->last_live = corewar->cycle;
	corewar_update_process_pc(corewar, process, 5);
	return (0);
}
