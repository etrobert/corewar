/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_aff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:48:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:21:33 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_aff(const t_corewar *corewar, int val)
{
	if (!corewar->print_aff)
		return (0);
	return (corewar_print_log(corewar, "Aff: %c\n", val));
}
