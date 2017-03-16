/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:13:06 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/16 16:50:15 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_aff(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	int				ret;

	if ((ret = corewar_parse_params(corewar, process, &params)) == 0)
		corewar_print_log(corewar, "Aff: %c\n", process_get_reg(process,
					params.params[0].c));
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
