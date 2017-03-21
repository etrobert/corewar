/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:05:34 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 15:06:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void				print_champs(t_list *champs)
{
	t_list_it		it;
	t_champion		*champ;

	it = ft_list_begin(champs);
	ft_printf("%d champions loaded : \n", ft_list_size(champs));
	while (!ft_list_it_end(champs, it))
	{
		champ = ft_list_it_get(champs, it);
		ft_printf("  - Player %u, \"%s\", (\"%s\"), weighs %u\n", champ->id,
				champ->header.prog_name, champ->header.comment,
				champ->header.prog_size);
		ft_list_it_inc(&it);
	}
}

