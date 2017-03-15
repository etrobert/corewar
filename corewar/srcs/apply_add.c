/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:03:11 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/14 21:46:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_add(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	int				arg[2];

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		arg[0] = corewar_extract_param(corewar, process, &params, 0);
		arg[1] = corewar_extract_param(corewar, process, &params, 1);
		process_set_reg(process, params.params[2].c, arg[0] + arg[1]);
		corewar_print_op(corewar, process,
				"add %d %d r%d -> %d\n",
				arg[0], arg[1], params.params[2].c,
				process_get_reg(process, params.params[2].c));
		if (process_get_reg(process, params.params[2].c) == 0)
			process->carry = true;
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
