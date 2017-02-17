/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:23:06 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/14 19:23:59 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

t_champion			*champion_new(void)
{
	t_champion		*champ;

	if ((champ = (t_champion *)(malloc(sizeof(t_champion)))) == NULL)
		return (NULL);
	return (champ);
}
