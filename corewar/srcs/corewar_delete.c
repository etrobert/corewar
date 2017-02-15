/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:37:57 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/15 20:38:45 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_delete(t_corewar *corewar)
{
	if (corewar == NULL)
		return ;
	ft_list_delete(corewar->process);
	free(corewar);
}
