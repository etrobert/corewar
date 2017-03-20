/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_get_winner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:35 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 21:51:58 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion			*corewar_get_winner(t_corewar *corewar)
{
	if (corewar == NULL)
		return (NULL);
	return (corewar->last_living_champ);
}
