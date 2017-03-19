/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:43:11 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/19 16:04:32 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			asm_init_header_and_labels(t_asm *m_asm)
{
	if (((m_asm->header) = (t_header*)malloc(sizeof(t_header))) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	ft_bzero(m_asm->header, sizeof(t_header));
	(m_asm->header)->magic = ft_uint32_big_endian(COREWAR_EXEC_MAGIC);
	(m_asm->header)->prog_size = 0;
	if ((m_asm->labels = ft_list_new()) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	return (1);
}

static int			asm_no_name_or_comment(int name, int comment, char *line,
		t_asm *m_asm)
{
	unsigned int		ret;

	if (name != NAME && comment != COMMENT)
	{
		ret = asm_get_line_size(line, &(m_asm->labels),
				(m_asm->header)->prog_size, m_asm);
		if (ret > CHAMP_MAX_SIZE)
			return (0);
		(m_asm->header)->prog_size += ret;
		if (((m_asm->header)->prog_size) > CHAMP_MAX_SIZE)
			ft_printf("Warning : champion is too big (max : %d)\n",
					CHAMP_MAX_SIZE);
	}
	return (1);
}

static int			asm_line_loop_one(t_asm *m_asm, char *line, t_list_it *it)
{
	int				comment;
	int				name;

	if (!(name = asm_get_prog_name(line, m_asm, it)) ||
			!(comment = asm_get_prog_comment(line, m_asm, it)))
		return (0);
	if ((name == NAME && !m_asm->name) ||
			(comment == COMMENT && !m_asm->comment))
	{
		ft_dprintf(2, "Champion must have only one name and comment.\n");
		return (0);
	}
	if (!asm_no_name_or_comment(name, comment, line, m_asm))
		return (0);
	return (1);
}

static int			asm_line_loop(t_asm *m_asm)
{
	char			*line;
	t_list_it		it;

	it = ft_list_begin(m_asm->file);
	while (!ft_list_it_end(m_asm->file, it))
	{
		line = (char*)ft_list_it_get(m_asm->file, it);
		if (!asm_line_loop_one(m_asm, line, &it))
			return (0);
		ft_list_it_inc(&it);
	}
	return (1);
}

int					asm_get_size(t_asm *m_asm)
{
	if (!asm_init_header_and_labels(m_asm))
		return (0);
	if (!asm_line_loop(m_asm))
		return (0);
	(m_asm->header)->prog_size =
		ft_uint32_big_endian((m_asm->header)->prog_size);
	return (1);
}
