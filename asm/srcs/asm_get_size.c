/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:43:11 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/19 19:08:22 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			asm_init_header_and_labels(t_header **header,
		t_list **labels)
{
	if (((*header) = (t_header*)malloc(sizeof(t_header))) == NULL)
		return (0);
	ft_bzero(*header, sizeof(t_header));
	(*header)->magic = ft_uint32_big_endian(COREWAR_EXEC_MAGIC);
	(*header)->prog_size = 0;
	if (((*labels) = ft_list_new()) == NULL)
		return (0);
	return (1);
}

static int			asm_new_label(t_list **labels, char *lab_name,
		unsigned int size)
{
	t_labels		*label;

	if ((label = (t_labels*)malloc(sizeof(t_labels))) == NULL)
		return (0);
	label->name = ft_strextract(lab_name, LABEL_CHAR);
	label->position = size;
	ft_list_push_back(*labels, label);
	return (1);
}

static int			asm_get_params_size(char **split, int n, t_op op_tab)
{
	int				i;
	unsigned int	size;

	size = 0;
	i = 0;
	while (split[n + i])
	{
		if (split[n + i][0] == COMMENT_CHAR || split[n + i][0] == ';')
			return (size);
		if (split[n + i][0] == 'r')
			size += 1;
		else if (split[n + i][0] == DIRECT_CHAR && op_tab.small_direct == true)
			size += 2;
		else if (split[n + i][0] == DIRECT_CHAR)
			size += 4;
		else
			size += 2;
		i++;
	}
	if (op_tab.ocp == true)
		return (size + 2);
	return (size + 1);
}

static unsigned int	asm_get_line_size(char *line, t_list **labels,
		unsigned int prog_size)
{
	unsigned int	size;
	char			**split;
	int				i;
	int				n;

	if (!(split = ft_strsplit_str(line, " \t,")))
		return (0);
	n = 0;
	if (split[n] && split[n][ft_strlen(split[n]) - 1] == LABEL_CHAR)
	{
		if (!asm_new_label(labels, split[n], prog_size))
			return (0);
		n++;
	}
	if (!split[n] || split[n][0] == COMMENT_CHAR || split[n][0] == ';')
		return (0);
	i = 0;
	while (g_op_tab[i].op_code > 0 && ft_strcmp(split[n], g_op_tab[i].name))
		i++;
	if (g_op_tab[i].op_code == 0)
		return (0);
	size = asm_get_params_size(split, n + 1, g_op_tab[i]);
	return (size);
}

int					asm_get_size(t_header **header, t_list **labels,
		t_list *file)
{
	int				name;
	int				comment;
	t_list_it		it;
	char			*line;
	unsigned int	size;

	if (!asm_init_header_and_labels(header, labels))
		return (0);
	it = ft_list_begin(file);
	size = 0;
	while (!ft_list_it_end(file, it))
	{
		line = ft_list_it_get(file, it);
		if (!(name = asm_get_prog_name(line, header)) ||
				!(comment = asm_get_prog_comment(line, header)))
			return (0);
		if (name != NAME && comment != COMMENT)
			size += asm_get_line_size(line, labels, (*header)->prog_size);
		ft_list_it_inc(&it);
	}
	(*header)->prog_size = ft_uint32_big_endian(size);
	return (1);
}
