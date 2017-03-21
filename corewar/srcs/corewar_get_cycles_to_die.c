/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_get_cycles_to_die.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:19:22 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/10 19:24:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cycle_type		corewar_get_cycles_to_die(t_corewar *corewar)
{
	return (corewar->cycles_to_die);
}
