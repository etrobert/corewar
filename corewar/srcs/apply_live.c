/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:48:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 17:05:04 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				apply_live(t_corewar *corewar, t_process *process)
{
	t_id_type	id;

	id = ft_uint32_big_endian(
				*(unsigned int *)(corewar->memory + process->pc + 1));
	ft_printf("un processus dit que le joueur %u(?) est en vie\n", id);
	corewar_update_process_pc(corewar, process, 5);
}
