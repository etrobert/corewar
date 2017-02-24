/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:37:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/24 20:36:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned int	corewar_parse_reg(t_corewar *corewar, t_process *process,
		t_cw_params *params)
{
	unsigned char	reg;

	ft_cbuff_read(corewar->memory, &reg, process->pc + params->offset,
			sizeof(unsigned char));
	++(params->offset);
	return (process_get_reg(process, reg));
}

static unsigned int	corewar_parse_ind(t_corewar *corewar, t_process *process,
		t_cw_params *params)
{
	short			addr;
	unsigned int	value;

	ft_cbuff_read(corewar->memory, &addr, process->pc + params->offset,
			sizeof(short));
	ft_cbuff_read(corewar->memory, &value, process->pc + (addr % IDX_MOD),
			sizeof(unsigned int));
	params->offset += 2;
	return (value);
}

static unsigned int	corewar_parse_dir(t_corewar *corewar, t_process *process,
		t_cw_params *params)
{
	unsigned short	val_short;
	unsigned int	val_int;

	if (process->current_op->small_direct)
	{
		ft_cbuff_read(corewar->memory, &val_short, process->pc + params->offset,
				sizeof(unsigned short));
		params->offset += 2;
		return (val_short);
	}
	else
	{
		ft_cbuff_read(corewar->memory, &val_int, process->pc + params->offset,
				sizeof(unsigned int));
		params->offset += 4;
		return (val_int);
	}
}

static int			corewar_parse_one_param(t_corewar *corewar,
		t_process *process, t_cw_params *params, int id)
{
	unsigned char	type;

	type = params->ocp >> ((id + 1) * 0xff);
	if (type == REG_CODE)
		params->params[id] = corewar_parse_reg(corewar, process, params);
	else if (type == DIR_CODE)
		params->params[id] = corewar_parse_dir(corewar, process, params);
	else if (type == IND_CODE)
		params->params[id] = corewar_parse_ind(corewar, process, params);
	// Actuellement il ne se passe rien si code incorrect ou 0
	return (0);
}

t_cw_params			corewar_parse_params(t_corewar *corewar, t_process *process)
{
	t_cw_params		params;

	params.offset = 1;
	ft_cbuff_read(corewar->memory, &(params.ocp), process->pc + params.offset,
			sizeof(unsigned char));
	++(params.offset);
	corewar_parse_one_param(corewar, process, &params, 0);
	corewar_parse_one_param(corewar, process, &params, 1);
	corewar_parse_one_param(corewar, process, &params, 2);
	return (params);
}
