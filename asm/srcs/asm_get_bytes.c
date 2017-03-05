/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:36:10 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/05 15:23:15 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_init_bytes(t_bytes **bytes_struct)
{
	t_bytes		*bytes;

	if ((*bytes_struct = (t_bytes*)malloc(sizeof(t_bytes))) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	bytes = *bytes_struct;
	bytes->ocp = 0;
	bytes->ocp_size = 0;
	bytes->param_size[0] = 0;
	bytes->param_size[1] = 0;
	bytes->param_size[2] = 0;
	return (1);
}

static int		asm_go_to_instruct(char **split, int *n, t_bytes **bytes)
{
	int		lab;

	lab = 0;
	if (split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		free(*bytes);
		return (1);
	}
	if (split[*n] && split[*n][ft_strlen(split[*n]) - 1] == LABEL_CHAR)
	{
		lab = 1;
		(*n)++;
	}
	if (!split[*n] || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		free(*bytes);
		if (lab == 1 || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
			return (1);
		return (0);
	}
	return (2);
}

static int		asm_get_line(char **split, t_bytes **bytes, t_asm *m_asm)
{
	int			n;
	int			ret;

	n = 0;
	if ((ret = asm_go_to_instruct(split, &n, bytes)) < 2)
		return (ret);
	if (((*bytes)->op_tab = get_op_by_name(split[n])) == NULL)
	{
		ft_dprintf(2, "Bad op\n");
		asm_free_split(split);
		free(*bytes);
		return (0);
	}
	if (!asm_get_params(split, n + 1, bytes, m_asm))
		return (0);
	return (2);
}

static int		asm_get_instruct(char *line, t_asm *m_asm)
{
	char		**split;
	t_bytes		*bytes;
	int			ret;

	if (!asm_init_bytes(&bytes))
		return (0);
	if (!(split = ft_strsplit_str(line, " \t,")))
	{
		free(bytes);
		return (0);
	}
	if ((ret = asm_get_line(split, &bytes, m_asm)) < 2)
		return (ret);
	if (ft_list_push_back(m_asm->instructs, bytes) < 0)
	{
		asm_free_split(split);
		free(bytes);
		return (0);
	}
	asm_free_split(split);
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
		line = (char*)ft_list_it_get(m_asm->file, it);
		if (!ft_strstr(line, NAME_CMD_STRING) &&
					!ft_strstr(line, COMMENT_CMD_STRING))
			if (!asm_get_instruct(line, m_asm))
				return (0);
		ft_list_it_inc(&it);
	}
	return (1);
}
