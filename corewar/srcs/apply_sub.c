/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:15:07 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 17:17:33 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int					apply_sub(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	int				arg[2];
	t_reg_type		val;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		arg[0] = corewar_extract_param(corewar, process, &params, 0);
		arg[1] = corewar_extract_param(corewar, process, &params, 1);
		val = arg[0] - arg[1];
		process_set_reg(process, params.params[2].c, val);
		corewar_print_op(corewar, process,
				"sub %d %d r%d -> %d\n",
				arg[0], arg[1], params.params[2].c, val);
		process->carry = (val == 0);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
