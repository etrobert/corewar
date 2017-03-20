/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:51:21 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 17:11:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_or(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	int				arg[2];
	t_reg_type		val;

	if (corewar_parse_params(corewar, process, &params) == FT_GOOD)
	{
		arg[0] = corewar_extract_param(corewar, process, &params, 0);
		arg[1] = corewar_extract_param(corewar, process, &params, 1);
		val = arg[0] | arg[1];
		process_set_reg(process, params.params[2].c, val);
		corewar_print_op(corewar, process,
				"or %d %d r%d -> %d\n",
				arg[0], arg[1], params.params[2].c, val);
		process->carry = (val == 0);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
