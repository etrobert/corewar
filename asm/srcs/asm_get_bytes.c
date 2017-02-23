/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:36:10 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/23 16:06:27 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_init_bytes(t_bytes **bytes_struct)
{
	t_bytes		*bytes;

	if ((*bytes_struct = (t_bytes*)malloc(sizeof(t_bytes))) == NULL)
		return (0);
	bytes = *bytes_struct;
	bytes->op_c = 0;
	bytes->op_c_size = 0;
	bytes->ocp = 0;
	bytes->ocp_size = 0;
	bytes->param_size[0] = 0;
	bytes->param_size[1] = 0;
	bytes->param_size[2] = 0;
	return (1);
}

static int		asm_get_instruct(char *line, t_asm *m_asm)
{
	char		**split;
	int			i;
	int			n;
	t_bytes		*bytes;

	if (!asm_init_bytes(&bytes))
		return (0);
	if (!(split = ft_strsplit_str(line, " \t,")))
		return (0);
	n = 0;
	if (split[n] && split[n][ft_strlen(split[n]) - 1] == LABEL_CHAR)
		n++;
	if (!split[n] || split[n][0] == COMMENT_CHAR || split[n][0] == ';')
		return (1);
	i = 0;
	while (g_op_tab[i].op_code > 0 && ft_strcmp(split[n], g_op_tab[i].name))
		i++;
	bytes->op_c = g_op_tab[i].op_code;
	asm_get_params(split, n + 1, &bytes, m_asm);
	bytes->op_c_size = 1;
	ft_list_push_back(m_asm->instructs, bytes);
	return (1);
}

int				asm_get_bytes(t_asm *m_asm)
{
	char		*line;
	t_list_it	it;

	if (!(m_asm->instructs = ft_list_new()))
		return (0);
	it = ft_list_begin(m_asm->file);
	while (!ft_list_it_end(m_asm->file, it))
	{
		line = ft_list_it_get(m_asm->file, it);
		if (!ft_strstr(line, NAME_CMD_STRING) &&
					!ft_strstr(line, COMMENT_CMD_STRING))
			if (!asm_get_instruct(line, m_asm))
				return (0);
		ft_list_it_inc(&it);
	}
	return (1);
}
