/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:12:12 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 20:27:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_xor(t_corewar *corewar, t_process *process)
{
	t_op_params		params;

	if (corewar_parse_params(corewar, process, &params) == FT_GOOD)
	{
		process_set_reg(process, params.params[2].c,
			corewar_extract_param(corewar, process, &params, 0) ^
			corewar_extract_param(corewar, process, &params, 1));
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
