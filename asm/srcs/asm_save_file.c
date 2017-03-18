/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_save_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:57:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/18 17:05:11 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_get_file(t_asm *m_asm, int fd)
{
	int		ret;
	char	*tmp;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((tmp = ft_strchr(line, COMMENT_CHAR)))
			*tmp = '\0';
		if ((tmp = ft_strchr(line, ';')))
			*tmp = '\0';
		if (ft_list_push_back(m_asm->file, line) < 0)
		{
			asm_free_file(m_asm->file);
			ft_dprintf(2, "Malloc error\n\n");
			return (0);
		}
	}
	if (ret < 0)
	{
		asm_free_file(m_asm->file);
		ft_dprintf(2, "Error while reading file\n");
		return (0);
	}
	return (1);
}

int			asm_save_file(int fd, t_asm *m_asm)
{
	if (((m_asm->file) = ft_list_new()) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	if (!asm_get_file(m_asm, fd))
		return (0);
	return (1);
}
