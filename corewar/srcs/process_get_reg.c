/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_get_reg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:31:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/24 20:32:26 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

t_reg_type			process_get_reg(t_process *proc, unsigned char reg)
{
	if (proc == NULL)
		return (0);
	if (reg >= REG_NUMBER)
		return (0);
	return (proc->regs[reg]);
}
