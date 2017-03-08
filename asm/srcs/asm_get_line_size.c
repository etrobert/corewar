/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_line_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:05:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/08 15:53:09 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_get_label(char *param, t_list **labels,
		unsigned int size)
{
	t_labels		*label;
	int				i;

	if ((label = (t_labels*)malloc(sizeof(t_labels))) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	label->name = ft_strextract(param, LABEL_CHAR);
	label->position = size;
	i = 0;
	while (label->name[i])
	{
		if (!ft_strchr(LABEL_CHARS, label->name[i++]))
		{
			ft_dprintf(2, "Bad char \'%c\' in label \'%s\'\n",
					label->name[i - 1], label->name);
			return (0);
		}
	}
	ft_list_push_back(*labels, label);
	return (1);
}

static int		asm_go_to_instruct(char **split, int *n, t_list **labels,
		unsigned int big_size)
{
	int		lab;

	lab = 0;
	if (!split[*n])
		return (0);
	if (split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		free(split);
		return (0);
	}
	if (split[*n] && split[*n][ft_strlen(split[*n]) - 1] == LABEL_CHAR)
	{
		lab = 1;
		if (!asm_get_label(split[*n], labels, big_size))
		{
			asm_free_split(split);
			return (-1);
		}
		(*n)++;
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

unsigned int	asm_get_line_size(char *line, t_list **labels,
		unsigned int big_size)
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
	n = 0;
	if ((ret = asm_go_to_instruct(split, &n, labels, big_size)) < 1)
		return (ret);
	if ((op_tab = get_op_by_name(split[n])) == NULL)
	{
		ft_dprintf(2, "Bad op [%s]\n", split[n]);
		asm_free_split(split);
		return (-1);
	}
	if ((size = asm_get_params_size(split, n + 1, op_tab))
			== (unsigned int)(-1))
		return (-1);
	asm_free_split(split);
	return (size);
}
