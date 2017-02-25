/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:43:11 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/25 17:31:04 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			asm_init_header_and_labels(t_asm *m_asm)
{
	if (((m_asm->header) = (t_header*)malloc(sizeof(t_header))) == NULL)
		return (0);
	ft_bzero(m_asm->header, sizeof(t_header));
	(m_asm->header)->magic = ft_uint32_big_endian(COREWAR_EXEC_MAGIC);
	(m_asm->header)->prog_size = 0;
	if ((m_asm->labels = ft_list_new()) == NULL)
		return (0);
	return (1);
}

static int			asm_get_label(char *param, t_list **labels,
		unsigned int size)
{
	t_labels		*label;

	if ((label = (t_labels*)malloc(sizeof(t_labels))) == NULL)
		return (0);
	label->name = ft_strextract(param, LABEL_CHAR);
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
		unsigned int big_size)
{
	unsigned int	size;
	char			**split;
	int				i;
	int				n;

	if (!(split = ft_strsplit_str(line, " \t,")))
		return (0);
	n = 0;
	if (split[n] && ft_strchr(split[n], LABEL_CHAR))
	{
		asm_get_label(split[n], labels, big_size);
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

int					asm_get_size(t_asm *m_asm)
{
	int				name;
	int				comment;
	t_list_it		it;
	char			*line;

	if (!asm_init_header_and_labels(m_asm))
		return (0);
	it = ft_list_begin(m_asm->file);
	while (!ft_list_it_end(m_asm->file, it))
	{
		line = (char*)ft_list_it_get(m_asm->file, it);
		if (!(name = asm_get_prog_name(line, &(m_asm->header))) ||
				!(comment = asm_get_prog_comment(line, &(m_asm->header))))
			return (0);
		if (name != NAME && comment != COMMENT)
			(m_asm->header)->prog_size += asm_get_line_size(line,
					&(m_asm->labels), (m_asm->header)->prog_size);
		ft_list_it_inc(&it);
	}
	(m_asm->header)->prog_size =
		ft_uint32_big_endian((m_asm->header)->prog_size);
	return (1);
}
