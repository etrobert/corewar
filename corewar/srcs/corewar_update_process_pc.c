/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_update_process_pc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:31:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/14 18:49:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_update_process_pc(t_corewar *corewar,
		t_process *proc, int value)
{
	(void)corewar;
	if (proc == NULL)
		return ;
	proc->pc = (proc->pc + value) % MEM_SIZE;
}
