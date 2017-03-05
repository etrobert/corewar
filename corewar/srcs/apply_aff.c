/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:13:06 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/02 22:04:13 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_aff(t_corewar *corewar, t_process *process)
{
	t_op_params		params;
	int				ret;

	ft_dprintf(2, "Jaffiche\n");
	if ((ret = corewar_parse_params(corewar, process, &params)) == 0)
		ft_dprintf(corewar->fd, "Aff: %c\n", process_get_reg(process,
					params.params[0].c));
	corewar_update_process_pc(corewar, process, params.offset);
	return (0);
}
