/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_get_last_live.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:51:47 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 18:53:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

t_cycle_type			champion_get_last_live(t_champion *champ)
{
	if (champ == NULL)
		return (0);
	return (champ->last_live);
}
