/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:22:53 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/23 15:58:32 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_add_ocp(t_bytes **bytes_instruct, unsigned char code)
{
	t_bytes		*bytes;
	int			i;

	bytes = *bytes_instruct;
	i = 0;
	while (g_op_tab[i].op_code > 0 && g_op_tab[i].op_code != bytes->op_c)
		i++;
	if (g_op_tab[i].ocp == true)
	{
		bytes->ocp += code;
		bytes->ocp <<= 2;
		bytes->ocp_size = 1;
	}
}

static void	asm_param_byte_reg(char *param, t_bytes **bytes_instruct, int i)
{
	t_bytes		*bytes;
	int			j;

	bytes = *bytes_instruct;
	j = 0;
	while (g_op_tab[j].op_code > 0 && g_op_tab[j].op_code != bytes->op_c)
		j++;
	asm_add_ocp(bytes_instruct, REG_CODE);
	bytes->param[i].c = ft_atoi(ft_strchr(param, 'r') + 1);
	bytes->param_size[i] = 1;
}

static unsigned int	asm_get_pos(t_list *instructs)
{
	t_list_it		it;
	unsigned int	pos;
	int				i;
	t_bytes			*bytes;

	pos = 0;
	it = ft_list_begin(instructs);
	while (!ft_list_it_end(instructs, it))
	{
		bytes = ft_list_it_get(instructs, it);
		pos += bytes->op_c_size;
		pos += bytes->ocp_size;
		i = 0;
		while (i < 3)
			pos += bytes->param_size[i++];
		ft_list_it_inc(&it);
	}
	return (pos);
}

static void	asm_param_byte_label(char *param, t_bytes **bytes_instruct,
		t_asm *m_asm, int i)
{
	t_list_it		it;
	t_labels		*label;
	int				j;
	unsigned int	pos;

	j = 0;
	while (g_op_tab[j].op_code > 0 && g_op_tab[j].op_code
			!= (*bytes_instruct)->op_c)
		j++;
	pos = asm_get_pos(m_asm->instructs);
	it = ft_list_begin(m_asm->labels);
	while (!ft_list_it_end(m_asm->labels, it))
	{
		label = ft_list_it_get(m_asm->labels, it);
		if (!strcmp(param, label->name) && g_op_tab[j].small_direct == true)
		{
			(*bytes_instruct)->param[i].s =
				ft_ushort16_big_endian(label->position - pos);
			(*bytes_instruct)->param_size[i] = 2;
		}
		else if (!strcmp(param, label->name))
		{
			(*bytes_instruct)->param[i].i =
				ft_uint32_big_endian(label->position - pos);
			(*bytes_instruct)->param_size[i] = 4;
		}
		ft_list_it_inc(&it);
	}
}

static void	asm_param_byte_dir(char *param, t_bytes **bytes_instruct,
		int i, t_asm *m_asm)
{
	t_bytes		*bytes;
	int			j;

	bytes = *bytes_instruct;
	j = 0;
	while (g_op_tab[j].op_code > 0 && g_op_tab[j].op_code != bytes->op_c)
		j++;
	asm_add_ocp(bytes_instruct, DIR_CODE);
	if (param[1] == LABEL_CHAR)
		asm_param_byte_label(ft_strchr(param, LABEL_CHAR) + 1, bytes_instruct,
				m_asm, i);
	else if (g_op_tab[j].small_direct == true)
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
}

static void	asm_param_byte_ind(char *param, t_bytes **bytes_instruct, int i)
{
	t_bytes		*bytes;

	bytes = *bytes_instruct;
	asm_add_ocp(bytes_instruct, IND_CODE);
	bytes->param[i].s = ft_ushort16_big_endian(ft_atoi(param));
	bytes->param_size[i] = 2;
}

void		asm_get_params(char **split, int n, t_bytes **bytes_instruct,
		t_asm *m_asm)
{
	int		i;

	i = 0;
	while (split[n + i])
	{
		if (split[n + i][0] == COMMENT_CHAR || split[n + i][0] == ';')
			return ;
		if (split[n + i][0] == 'r')
			asm_param_byte_reg(split[n + i], bytes_instruct, i);
		else if (split[n + i][0] == DIRECT_CHAR)
			asm_param_byte_dir(split[n + i], bytes_instruct, i, m_asm);
		else
			asm_param_byte_ind(split[n + i], bytes_instruct, i);
		i++;
	}
}
