/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_death.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:18:39 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/15 18:20:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_death(t_corewar *corewar, t_process *process)
{
	if ((corewar->verbosity & CW_VB_DEATHS) == 0)
		return (0);
	return (corewar_print_log(corewar, "A process on pc:[%d] died\n",
					process->pc));
}
