/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:46:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 16:58:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_lldi(t_corewar *corewar, t_process *process)
{
	int				arg[2];
	t_op_params		params;
	t_reg_type		val;
	int				dest;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		arg[0] = corewar_extract_param(corewar, process, &params, 0);
		arg[1] = corewar_extract_param(corewar, process, &params, 1);
		dest = arg[0] + arg[1];
		ft_cbuff_read(corewar->memory, &val, process->pc + dest,
				sizeof(t_reg_type));
		val = ft_uint32_big_endian(val);
		process_set_reg(process, params.params[2].c, val);
		corewar_print_op(corewar, process,
				"ldi %d %d r%d -> loads %d from %d\n",
				arg[0], arg[1], params.params[2].c,
				process_get_reg(process, params.params[2].c), dest);
		process->carry = (val == 0);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
