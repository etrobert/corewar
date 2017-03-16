/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:47:11 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 22:11:20 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			apply_st_ind(t_corewar *corewar, t_process *process,
		unsigned int val, t_op_params *params)
{
	val = ft_uint32_big_endian(val);
	corewar_write(corewar, (t_memory){&val, sizeof(unsigned int)},
			process->pc + (short)(params->params[1].s),
			corewar_get_byte_id(corewar, process->pc));
}

int					apply_st(t_corewar *corewar, t_process *process)
{
	unsigned int	val;
	t_op_params		params;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		val = corewar_extract_param(corewar, process, &params, 0);
		if (ocp_get_type(params.ocp, 1) == IND_CODE)
		{
			corewar_print_op(corewar, process,
					"st r%d(%d) %hd\n",
					params.params[0].c, val, params.params[1].s);
			apply_st_ind(corewar, process, val, &params);
		}
		else
		{
			corewar_print_op(corewar, process,
					"st r%d(%d) r%d\n",
					params.params[0].c, val, params.params[1].c);
			process_set_reg(process, params.params[1].c, val);
		}
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
