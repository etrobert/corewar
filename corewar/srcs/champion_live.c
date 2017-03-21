/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:31:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 18:47:04 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

void					champion_live(t_champion *champ,
		t_cycle_type cycle)
{
	if (champ == NULL)
		return ;
	++(champ->period_lives);
	champ->last_live = cycle;
}
