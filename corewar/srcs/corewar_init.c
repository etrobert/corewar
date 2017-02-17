/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:36:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:43:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			add_fresh_process(t_corewar *corewar,
		t_reg_type pc, t_reg_type r1)
{
	t_process		*process;

	if ((process = process_new()) == NULL)
		return (-1);
	process->pc = pc;
	process->regs[1] = r1;
	corewar_update_process(corewar, process);
	ft_list_push_front(corewar->process, process);
	return (0);
}

int					corewar_init(t_corewar *corewar, t_list *champions)
{
	t_champion		*champ;

	if (corewar == NULL)
		return (0);
	if ((corewar->process = ft_list_new()) == NULL)
		return (-1);

	champ = (t_champion *)(ft_list_front(champions));
	//Attention cyclique
	ft_memmove(corewar->memory, champ->code, champ->header.prog_size);
	if (add_fresh_process(corewar, champ->id, 0) == -1)
		return (-1);
	return (0);
}
