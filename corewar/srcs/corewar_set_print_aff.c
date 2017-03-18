/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_set_print_aff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:44:30 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/16 15:45:35 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_set_print_aff(t_corewar *corewar, bool print_aff)
{
	if (corewar == NULL)
		return ;
	corewar->print_aff = print_aff;
}
