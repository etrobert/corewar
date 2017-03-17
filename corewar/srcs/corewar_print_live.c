/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_live.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:22:23 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/15 17:48:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_live(t_corewar *corewar, unsigned int id)
{
	if ((corewar->verbosity & CW_VB_LIVE) == 0)
		return (0);
	return (corewar_print_log(corewar,
				"un processus dit que le joueur %u(?) est en vie\n", id));
}
