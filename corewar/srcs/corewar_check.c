/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:24:22 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 18:47:25 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			dec_cycles_to_die(t_corewar *corewar)
{
	if (corewar->cycles_to_die < CYCLE_DELTA)
		corewar->cycles_to_die = 0;
	else
		corewar->cycles_to_die -= CYCLE_DELTA;
	corewar->clear_checks = 0;
	corewar_print_cycles_to_die(corewar);
}

static void			new_period(t_corewar *corewar)
{
	t_list_it		it;

	it = ft_list_begin(corewar->champions);
	while (!ft_list_it_end(corewar->champions, it))
	{
		champion_new_period(
				(t_champion *)ft_list_it_get(corewar->champions, it));
		ft_list_it_inc(&it);
	}
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
	new_period(corewar);
	corewar->nbr_live = 0;
	corewar->last_check = corewar->cycle;
}
