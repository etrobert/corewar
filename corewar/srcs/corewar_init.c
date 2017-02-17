/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:36:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/15 19:55:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_init(t_corewar *corewar, t_list *champions)
{
	t_champion		*champ;
	t_process		*process;

	if (corewar == NULL)
		return (0);
	if ((corewar->process = ft_list_new()) == NULL)
		return (-1);

	champ = (t_champion *)(ft_list_front(champions));
	//Attention cyclique
	ft_memmove(corewar->memory, champ->code, champ->header.prog_size);
	if ((process = process_new(champ->id, 0)) == NULL)
		return (-1);
	ft_list_push_back(corewar->process, process);
	return (0);
}
