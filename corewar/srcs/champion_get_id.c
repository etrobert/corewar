/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_get_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:06:22 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 18:06:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

t_id_type				champion_get_id(t_champion *champion)
{
	if (champion == NULL)
		return (-1);
	return (champion->id);
}
