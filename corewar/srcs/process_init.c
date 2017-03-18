/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:44:33 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/07 16:42:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void				process_init(t_process *proc)
{
	int				i;

	if (proc == NULL)
		return ;
	i = 0;
	while (i < REG_NUMBER)
	{
		proc->regs[i] = 0;
		++i;
	}
	proc->pc = 0;
	proc->current_op = NULL;
	proc->new_instr = true;
	proc->to_wait = 0;
	proc->last_live = 0;
}
