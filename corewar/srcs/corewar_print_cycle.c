/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_cycle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:50:39 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/22 14:52:54 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_cycle(const t_corewar *corewar)
{
	if ((corewar->verbosity & CW_VB_CYCLES) == 0)
		return (0);
	return (corewar_print_log(corewar, "Current cycle is %u\n",
				corewar->cycle + 1));
}
