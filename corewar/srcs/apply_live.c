/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:48:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 18:49:42 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		apply_live_update(t_corewar *corewar, t_process *process,
		unsigned int id)
{
	t_champion		*champion;

	corewar_print_op(corewar, process, "live %u\n", id);
	process->last_live = corewar->cycle;
	++(corewar->nbr_live);
	if ((champion = corewar_id_champ(corewar, id)) == NULL)
		return ;
	champion_live(champion, corewar->cycle);
	corewar->last_living_champ = champion;
	corewar_print_live(corewar, id);
}

int					apply_live(t_corewar *corewar, t_process *process)
{
	unsigned int	id;

	corewar_read(corewar, (t_memory){&id, sizeof(id)}, process->pc + 1);
	id = ft_uint32_big_endian(id);
	apply_live_update(corewar, process, id);
	corewar_update_process_pc(corewar, process, 5);
	return (0);
}
