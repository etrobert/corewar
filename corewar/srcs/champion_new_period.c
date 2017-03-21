/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_new_period.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:43:52 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 18:47:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

void					champion_new_period(t_champion *champ)
{
	if (champ == NULL)
		return ;
	champ->period_lives = 0;
}
