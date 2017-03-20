/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:37:57 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/19 19:17:25 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_delete(t_corewar *corewar)
{
	if (corewar == NULL)
		return ;
	ft_list_apply(corewar->process, (t_f_apply)&process_delete);
	ft_list_delete(corewar->process);
	ft_cbuff_delete(corewar->memory);
	ft_cbuff_delete(corewar->memory_id);
	free(corewar);
}
