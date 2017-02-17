/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:59:47 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 18:23:47 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_id_type			corewar_play(t_corewar *corewar)
{
	int				i;

	if (corewar == NULL)
		return (0);
	i = 0;
	while (!ft_list_empty(corewar->process))
	{
		corewar_advance(corewar);
		++i;
	}
	return (0);
}
