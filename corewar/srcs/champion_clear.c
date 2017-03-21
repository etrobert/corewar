/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:30:02 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/07 16:39:58 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

void					champion_clear(t_champion *champion)
{
	free(champion->code);
}
