/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_nothing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:42:50 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 13:31:41 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_nothing(t_corewar *corewar, t_process *process)
{
	(void)corewar;
	corewar_update_process_pc(corewar, process, 1);
	return (0);
}
