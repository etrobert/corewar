/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_extract_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:40:42 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 18:58:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned int	corewar_extract_param_ind(const t_corewar *corewar,
		const t_process *process, const t_op_params *params, unsigned char id)
{
	unsigned int	val;

	//modulo ??
	ft_cbuff_read(corewar->memory, &val,
			process->pc + (short)params->params[id].s, sizeof(unsigned int));
	return (ft_uint32_big_endian(val));
}

unsigned int		corewar_extract_param(const t_corewar *corewar,
		const t_process *process, const t_op_params *params, unsigned char id)
{
	char			type;

	if (params == NULL)
		return (0);
	if (id < 0 || id > 3)
		return (0);
	type = ocp_get_type(params->ocp, id);
	if (type == REG_CODE)
		return (process_get_reg(process, params->params[id].c));
	else if (type == DIR_CODE)
	{
		if (process->current_op->small_direct)
			return ((short)params->params[id].s);
		return (params->params[id].i);
	}
	else if (type == IND_CODE)
		return (corewar_extract_param_ind(corewar, process, params, id));
	return (0);
}
