/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_cycles_to_die.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:02:50 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:23:13 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_cycles_to_die(const t_corewar *corewar)
{
	if ((corewar->verbosity & CW_VB_CYCLES) == 0)
		return (0);
	return (corewar_print_log(corewar, "Cycle to die is now %u\n",
				corewar->cycles_to_die));
}
