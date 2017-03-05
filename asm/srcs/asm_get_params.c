/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:22:53 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/05 14:27:24 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_add_ocp(t_bytes **bytes_instruct, unsigned char code)
{
	t_bytes		*bytes;

	bytes = *bytes_instruct;
	if (bytes->op_tab->ocp == true)
	{
		bytes->ocp += code;
		bytes->ocp <<= 2;
		bytes->ocp_size = 1;
	}
}

static void	asm_param_byte_reg(char *param, t_bytes **bytes_instruct, int i)
{
	t_bytes		*bytes;
	int			reg;

	bytes = *bytes_instruct;
	asm_add_ocp(bytes_instruct, REG_CODE);
	reg = ft_atoi(ft_strchr(param, 'r') + 1);
	bytes->param[i].c = reg;
	bytes->param_size[i] = 1;
}

static int		asm_param_byte_dir(char *param, t_bytes **bytes_instruct,
		int i, t_asm *m_asm)
{
	t_bytes		*bytes;

	bytes = *bytes_instruct;
	asm_add_ocp(bytes_instruct, DIR_CODE);
	if (param[1] == LABEL_CHAR)
	{
		if (!asm_param_byte_label_dir(ft_strchr(param, LABEL_CHAR) + 1,
				bytes_instruct, m_asm, i))
			return (0);
	}
	else if (bytes->op_tab->small_direct == true)
	{
		bytes->param[i].s =
			ft_ushort16_big_endian(ft_atoi(ft_strchr(param, DIRECT_CHAR) + 1));
		bytes->param_size[i] = 2;
	}
	else
	{
		bytes->param[i].i =
			ft_uint32_big_endian(ft_atoi(ft_strchr(param, DIRECT_CHAR) + 1));
		bytes->param_size[i] = 4;
	}
	return (1);
}

static int		asm_param_byte_ind(char *param, t_bytes **bytes_instruct, int i,
		t_asm *m_asm)
{
	t_bytes		*bytes;

	bytes = *bytes_instruct;
	asm_add_ocp(bytes_instruct, IND_CODE);
	if (param[0] == LABEL_CHAR)
	{
		if (!asm_param_byte_label_ind(param + 1, bytes_instruct, m_asm, i))
			return (0);
	}
	else
	{
		bytes->param[i].s = ft_ushort16_big_endian(ft_atoi(param));
		bytes->param_size[i] = 2;
	}
	return (1);
}

int			asm_get_params(char **split, int n, t_bytes **bytes_instruct,
		t_asm *m_asm)
{
	int		i;

	i = 0;
	while (split[n + i])
	{
		if (split[n + i][0] == COMMENT_CHAR || split[n + i][0] == ';')
			return (1);
		if (split[n + i][0] == 'r')
			asm_param_byte_reg(split[n + i], bytes_instruct, i);
		else if (split[n + i][0] == DIRECT_CHAR)
		{
			if (!asm_param_byte_dir(split[n + i], bytes_instruct, i, m_asm))
				return (0);
		}
		else if (!asm_param_byte_ind(split[n + i], bytes_instruct, i, m_asm))
				return (0);
		i++;
	}
	return (1);
}
