/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:13:06 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 13:41:30 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_aff(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	int				ret;
	int				val;

	if ((ret = corewar_parse_params(corewar, process, &params)) == 0)
	{
		val = process_get_reg(process, params.params[0].c);
		corewar_print_op(corewar, process, "aff %d\n", val);
		corewar_print_aff(corewar, val);
	}
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
