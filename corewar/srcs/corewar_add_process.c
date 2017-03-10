/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_add_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:24:46 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/08 16:54:38 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_add_process(t_corewar *corewar, t_process *process)
{
	corewar_update_process(corewar, process);
	return (ft_list_push_front(corewar->process, process));
}
