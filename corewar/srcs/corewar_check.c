/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:24:22 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 12:24:51 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			dec_cycles_to_die(t_corewar *corewar)
{
	corewar->cycles_to_die -= CYCLE_DELTA;
	corewar->clear_checks = 0;
}

void				corewar_check(t_corewar *corewar)
{
	corewar_kill_process(corewar);
	if (corewar->nbr_live >= NBR_LIVE)
		dec_cycles_to_die(corewar);
	else
	{
		++(corewar->clear_checks);
		if (corewar->clear_checks >= MAX_CHECKS)
			dec_cycles_to_die(corewar);
	}
	corewar->nbr_live = 0;
	corewar->last_check = corewar->cycle;
}

