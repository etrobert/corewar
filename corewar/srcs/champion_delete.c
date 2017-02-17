/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:25:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/14 20:31:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

void				champion_delete(t_champion *champion)
{
	if (champion == NULL)
		return ;
	free(champion->code);
	free(champion);
}
