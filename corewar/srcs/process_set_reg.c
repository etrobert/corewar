/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_set_reg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 20:18:53 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 20:36:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void				process_set_reg(t_process *proc, unsigned char reg,
		unsigned int val)
{
	if (proc == NULL)
		return ;
	if (!process_valid_reg(reg))
		return ;
	proc->regs[reg - 1] = val;
}
