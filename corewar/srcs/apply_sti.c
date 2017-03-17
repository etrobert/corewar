/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:04:47 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/16 16:57:29 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			apply_sti_write(t_corewar *corewar, t_process *process,
		unsigned int val, int dest)
{
	val = ft_uint32_big_endian(val);
	// % here ? to prevent overflow
	corewar_write(corewar, (t_memory){&val, sizeof(unsigned int)},
			process->pc + (dest % IDX_MOD),
			corewar_get_byte_id(corewar, process->pc));
}

int					apply_sti(t_corewar *corewar, t_process *process)
{
	unsigned int	val;
	int				arg[2];
	int				dest;
	t_op_params		params;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		val = corewar_extract_param(corewar, process, &params, 0);
		//dest = (corewar_extract_param(corewar, process, &params, 1) % IDX_MOD) +
		//	(corewar_extract_param(corewar, process, &params, 2) % IDX_MOD);
		arg[0] = corewar_extract_param(corewar, process, &params, 1);
		arg[1] = corewar_extract_param(corewar, process, &params, 2);
		//OVERFLOW ???
		dest = arg[0] + arg[1];
		corewar_print_op(corewar, process,
				"sti r%d(%d) %d %d -> store to %d\n",
				params.params[0].c, val, arg[0], arg[1], dest);
		apply_sti_write(corewar, process, val, dest);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
