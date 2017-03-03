/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:37:16 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/03 16:31:25 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			corewar_parse_reg(t_corewar *corewar, t_process *process,
		t_op_params *params, int id)
{
	ft_cbuff_read(corewar->memory, &((params->params[id]).c),
			process->pc + params->offset, sizeof(unsigned char));
	++(params->offset);
}

static void			corewar_parse_ind(t_corewar *corewar, t_process *process,
		t_op_params *params, int id)
{
	ft_cbuff_read(corewar->memory, &(params->params[id].s),
			process->pc + params->offset, sizeof(unsigned short));
	params->offset += 2;
}

static void			corewar_parse_dir(t_corewar *corewar, t_process *process,
		t_op_params *params, int id)
{
	if (process->current_op->small_direct)
	{
		ft_cbuff_read(corewar->memory, &(params->params[id].s),
				process->pc + params->offset, sizeof(unsigned short));
		params->offset += 2;
	}
	else
	{
		ft_cbuff_read(corewar->memory, &(params->params[id].i),
				process->pc + params->offset, sizeof(unsigned int));
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
		if (params->params[id].c >= REG_NUMBER)
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
	ft_cbuff_read(corewar->memory, &(params->ocp), process->pc + params->offset,
			sizeof(unsigned char));
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
