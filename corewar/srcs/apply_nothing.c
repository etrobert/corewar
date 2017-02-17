/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_nothing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:42:50 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:23:51 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				apply_nothing(t_corewar *corewar, t_process *process)
{
	(void)corewar;
	process->pc = (process->pc + 1) % MEM_SIZE;
}
