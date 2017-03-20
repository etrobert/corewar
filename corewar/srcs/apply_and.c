/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 00:50:10 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 19:22:18 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_and(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	int				arg[2];

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		arg[0] = corewar_extract_param(corewar, process, &params, 0);
		arg[1] = corewar_extract_param(corewar, process, &params, 1);
		process_set_reg(process, params.params[2].c, arg[0] & arg[1]);
		corewar_print_op(corewar, process,
				"and %d %d r%d -> %d\n",
				arg[0], arg[1], params.params[2].c,
				process_get_reg(process, params.params[2].c));
		//A verifier
		process->carry = (process_get_reg(process, params.params[2].c) == 0);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
