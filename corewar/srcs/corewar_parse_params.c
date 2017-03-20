/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:37:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 19:31:12 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			corewar_parse_reg(t_corewar *corewar, t_process *process,
		t_op_params *params, int id)
{
	corewar_read(corewar, (t_memory){&((params->params[id]).c),
			sizeof(unsigned char)}, process->pc + params->offset);
	++(params->offset);
}

static void			corewar_parse_ind(t_corewar *corewar, t_process *process,
		t_op_params *params, int id)
{
	corewar_read(corewar, (t_memory){&((params->params[id].s)),
			sizeof(unsigned short)}, process->pc + params->offset);
	params->params[id].s = ft_ushort16_big_endian(params->params[id].s);
	params->offset += 2;
}

static void			corewar_parse_dir(t_corewar *corewar, t_process *process,
		t_op_params *params, int id)
{
	if (process->current_op->small_direct)
	{
		corewar_read(corewar, (t_memory){&((params->params[id]).s),
				sizeof(unsigned short)}, process->pc + params->offset);
		params->params[id].s = ft_ushort16_big_endian(params->params[id].s);
		params->offset += 2;
	}
	else
	{
		corewar_read(corewar, (t_memory){&((params->params[id]).i),
				sizeof(unsigned int)}, process->pc + params->offset);
		params->params[id].i = ft_uint32_big_endian(params->params[id].i);
		params->offset += 4;
	}
}

static int			corewar_parse_one_param(t_corewar *corewar,
		t_process *process, t_op_params *params, int id)
{
	unsigned char	type;

	type = ocp_get_type(params->ocp, id);
	if (type == REG_CODE)
	{
		corewar_parse_reg(corewar, process, params, id);
		if (!process_valid_reg(params->params[id].c))
//		if (params->params[id].c >= REG_NUMBER)
			return (-1);
	}
	else if (type == DIR_CODE)
		corewar_parse_dir(corewar, process, params, id);
	else if (type == IND_CODE)
		corewar_parse_ind(corewar, process, params, id);
	// Actuellement il ne se passe rien si le code est 00
	if ((process->current_op->params[id] & type) == 0)
		return (-1);
	return (0);
}

int					corewar_parse_params(t_corewar *corewar, t_process *process,
		t_op_params *params)
{
	int				i;
	int				ret;
	int				tmp;

	params->offset = 1;
	corewar_read(corewar, (t_memory){&(params->ocp), sizeof(unsigned char)},
			process->pc + params->offset);
	++(params->offset);
	ret = 0;
	i = 0;
	while (i < process->current_op->nb_params)
	{
		if ((tmp = corewar_parse_one_param(corewar, process, params, i)) != 0)
			ret = tmp;
		++i;
	}
	return (ret);
}
