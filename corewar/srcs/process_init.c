/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:44:33 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 00:55:40 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void				process_init(t_process *proc, t_reg_type r1, t_reg_type pc)
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
	proc->regs[0] = r1;
	proc->pc = pc;
	proc->to_wait = 0;
}
