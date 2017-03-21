/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_id_champ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:27:29 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 10:55:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion			*corewar_id_champ(const t_corewar *corewar, t_id_type id)
{
	t_list_it		it;
	t_champion		*champ;

	it = ft_list_begin(corewar->champions);
	while (!ft_list_it_end(corewar->champions, it))
	{
		champ = (t_champion *)ft_list_it_get(corewar->champions, it);
		if (champ->intern_id == id)
			return (champ);
		ft_list_it_inc(&it);
	}
	return (NULL);
}
