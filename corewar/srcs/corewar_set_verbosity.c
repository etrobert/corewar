/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_set_verbosity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:29:33 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/15 17:29:34 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_set_verbosity(t_corewar *corewar, int verbosity)
{
	if (corewar == NULL)
		return ;
	corewar->verbosity = verbosity;
}
