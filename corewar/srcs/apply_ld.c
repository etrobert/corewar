/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:41:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 20:51:56 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_ld(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	unsigned int	val;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		val = corewar_extract_param(corewar, process, &params, 0);
		process_set_reg(process, params.params[1].c, val);
		corewar_print_log(corewar, "pc %d: ld %d r%d\n",
				process->pc, val, params.params[1].c);
		if (val == 0)
			process->carry = true;
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
