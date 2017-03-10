/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:04:47 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/10 19:54:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			apply_sti_write(t_corewar *corewar, t_process *process,
		unsigned int val, int dest)
{
	val = ft_uint32_big_endian(val);
	corewar_write(corewar, (t_memory){&val, sizeof(unsigned int)},
			process->pc + dest,
			corewar_get_byte_id(corewar, process->pc));
}

static void			apply_sti_log(t_corewar *corewar, t_process *process,
		unsigned int val, unsigned int dest)
{
	char			*log;

	ft_asprintf(&log, "[sti] a process of pc %d is writing %d at +%d",
				process->pc, val, dest);
	corewar_print_log(corewar, log);
	free(log);
}

int					apply_sti(t_corewar *corewar, t_process *process)
{
	unsigned int	val;
	unsigned int	dest;
	t_op_params		params;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		val = corewar_extract_param(corewar, process, &params, 0);
		dest = (corewar_extract_param(corewar, process, &params, 1) % IDX_MOD) +
			(corewar_extract_param(corewar, process, &params, 2) % IDX_MOD);
		apply_sti_log(corewar, process, val, dest);
		apply_sti_write(corewar, process, val, dest);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
