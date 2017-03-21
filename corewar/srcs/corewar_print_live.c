/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_live.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:22:23 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:22:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_live(const t_corewar *corewar,
		unsigned int id)
{
	t_champion		*champ;

	if ((corewar->verbosity & CW_VB_LIVE) == 0)
		return (0);
	champ = corewar_id_champ(corewar, id);
	if (champ == NULL)
		return (0);
	return (corewar_print_log(corewar,
				"un processus dit que le joueur %d(%s) est en vie\n",
				champ->id, champ->header.prog_name));
}
