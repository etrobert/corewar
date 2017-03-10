/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:22:53 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/10 18:29:16 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_add_ocp(t_bytes **bytes_instruct, unsigned char code)
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

static int		asm_param_byte_reg(char *param, t_bytes **bytes_instruct, int i)
{
	t_bytes		*bytes;
	int			reg;

	if (param[0] != 'r' || !ft_str_test_chars(param + 1, &ft_isdigit))
	{
		ft_dprintf(2, "Bad syntax for register \'%s\'\n", param);
		return (0);
	}
	bytes = *bytes_instruct;
	asm_add_ocp(bytes_instruct, REG_CODE);
	reg = ft_atoi(param + 1);
	bytes->param[i].c = reg;
	bytes->param_size[i] = 1;
	return (1);
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
	else if (!param[1] ||
			(param[1] == '-' && !ft_str_test_chars(param + 2, &ft_isdigit)) ||
			(param[1] != '-' && !ft_str_test_chars(param + 1, &ft_isdigit)))
	{
		ft_dprintf(2, "Bad syntax for direct \'%s\'\n", param);
		return (0);
	}
	else if (bytes->op_tab->small_direct == true)
	{
		bytes->param[i].s =
			ft_short16_big_endian(ft_atoi(ft_strchr(param, DIRECT_CHAR) + 1));
		bytes->param_size[i] = 2;
	}
	else
	{
		bytes->param[i].i =
			ft_int32_big_endian(ft_atoi(ft_strchr(param, DIRECT_CHAR) + 1));
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
	else if (!param[0] ||
			(param[0] == '-' && !ft_str_test_chars(param + 1, &ft_isdigit)) ||
			(param[0] != '-' && !ft_str_test_chars(param, &ft_isdigit)))
	{
		ft_dprintf(2, "Bad syntax for indirect \'%s\'\n", param);
		return (0);
	}
	else
	{
		bytes->param[i].s = ft_short16_big_endian(ft_atoi(param));
		bytes->param_size[i] = 2;
	}
	return (1);
}

int				asm_get_params(char **split, int n, t_bytes **bytes_instruct,
		t_asm *m_asm)
{
	int		i;

	i = 0;
	while (split[n + i])
	{
		if (split[n + i][0] == COMMENT_CHAR || split[n + i][0] == ';')
		{
			asm_complete_ocp(bytes_instruct, i);
			return (1);
		}
		if (split[n + i][0] == 'r')
		{
			if (!asm_param_byte_reg(split[n + i], bytes_instruct, i))
				return (0);
		}
		else if (split[n + i][0] == DIRECT_CHAR)
		{
			if (!asm_param_byte_dir(split[n + i], bytes_instruct, i, m_asm))
				return (0);
		}
		else if (!asm_param_byte_ind(split[n + i], bytes_instruct, i, m_asm))
			return (0);
		i++;
	}
	asm_complete_ocp(bytes_instruct, i);
	return (1);
}
