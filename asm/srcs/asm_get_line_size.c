/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_line_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:05:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/14 16:19:57 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_skip_comment_and_empty(char **split, int *n)
{
	if (!split[*n])
	{
		asm_free_split(split);
		return (0);
	}
	if (split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		return (0);
	}
	return (1);
}

static int		asm_go_to_instruct_size(char **split, int *n, t_list **labels,
		unsigned int big_size)
{
	int		lab;

	lab = 0;
	if (!asm_skip_comment_and_empty(split, n))
		return (0);
	if (split[*n] && ft_strchr(split[*n], LABEL_CHAR))
	{
		lab = 1;
		if (!asm_get_label(&(split[*n]), labels, big_size, n))
		{
			asm_free_split(split);
			return (-1);
		}
	}
	if (!split[*n] || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		if (lab == 1 || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
			return (0);
		return (-1);
	}
	return (1);
}

static int		asm_check_name_and_comment(t_asm *m_asm, char **split)
{
	if (!m_asm->name || !m_asm->comment)
	{
		ft_dprintf(2, "Champion must begin by name and comment\n");
		asm_free_split(split);
		return (0);
	}
	return (1);
}

static int		asm_check_op(char **split, int n, t_op **op_tab)
{
	if ((*op_tab = get_op_by_name(split[n])) == NULL)
	{
		ft_dprintf(2, "Bad op \'%s\'\n", split[n]);
		asm_free_split(split);
		return (0);
	}
	return (1);
}

unsigned int	asm_get_line_size(char *line, t_list **labels,
		unsigned int big_size, t_asm *m_asm)
{
	unsigned int	size;
	char			**split;
	int				n;
	int				ret;
	t_op			*op_tab;

	if ((split = ft_strsplit_str(line, " \t,")) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (-1);
	}
	if (!asm_check_name_and_comment(m_asm, split))
		return (-1);
	n = 0;
	if ((ret = asm_go_to_instruct_size(split, &n, labels, big_size)) < 1)
		return (ret);
	if (!asm_check_op(split, n, &op_tab))
		return (-1);
	if ((size = asm_get_params_size(split, n + 1, op_tab)) > CHAMP_MAX_SIZE
			|| !asm_check_separators(line, op_tab))
	{
		asm_free_split(split);
		return (-1);
	}
	asm_free_split(split);
	return (size);
}
