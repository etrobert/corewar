/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:59:47 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:04:01 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_id_type			corewar_play(t_corewar *corewar)
{
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		corewar_advance(corewar);
		++i;
	}
	return (0);
}
