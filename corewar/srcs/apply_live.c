/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:48:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:48:13 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				apply_live(t_corewar *corewar, t_process *process)
{
	t_id_type	id;

	id = *(unsigned int *)(corewar->memory + process->pc);
	ft_printf("un processus dit que le joueur %u(?) est en vie", id);
	process->pc = (process->pc + 4) % MEM_SIZE;
}
