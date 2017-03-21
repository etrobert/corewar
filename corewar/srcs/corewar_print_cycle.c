/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_cycle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:50:39 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:22:59 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_cycle(const t_corewar *corewar)
{
	if ((corewar->verbosity & CW_VB_CYCLES) == 0)
		return (0);
	return (corewar_print_log(corewar, "Is is now cycle %u\n",
				corewar->cycle + 1));
}
