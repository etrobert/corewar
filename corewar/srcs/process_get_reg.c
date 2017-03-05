/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_get_reg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:31:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/03 19:42:25 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

t_reg_type			process_get_reg(const t_process *proc, unsigned char reg)
{
	if (proc == NULL)
		return (0);
	if (reg >= REG_NUMBER)
		return (0);
	return (proc->regs[reg]);
}
