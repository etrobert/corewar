/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:43:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/14 19:00:12 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_lld(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	unsigned int	val;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		val = corewar_extract_param(corewar, process, &params, 0);
		process_set_reg(process, params.params[1].c, val);
		corewar_print_op(corewar, process, "lld %d r%d\n",
				val, params.params[1].c);
		if (val == 0)
			process->carry = true;
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
