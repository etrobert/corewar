/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:41:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/10 17:58:05 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_ld(t_corewar *corewar, t_process *process)
{
	t_op_params		params;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		process->regs[params.params[1].c] = corewar_extract_param(corewar,
				process, &params, 0);
		ft_dprintf(corewar->fd, "a process on pc %d is loading %d in register %d\n",
				process->pc,
				corewar_extract_param(corewar, process, &params, 0),
				params.params[1].c);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
