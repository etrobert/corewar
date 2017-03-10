/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 00:50:10 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/06 18:34:12 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_and(t_corewar *corewar, t_process *process)
{
	t_op_params		params;

	if (corewar_parse_params(corewar, process, &params) == 0)
	{
		process->regs[params.params[2].c] =
			corewar_extract_param(corewar, process, &params, 0) &
			corewar_extract_param(corewar, process, &params, 1);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
