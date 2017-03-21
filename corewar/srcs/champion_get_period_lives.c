/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_get_period_lives.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:49:10 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 16:50:21 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int			champion_get_period_lives(t_champion *champ)
{
	if (champ == NULL)
		return (0);
	return (champ->period_lives);
}
