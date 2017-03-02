/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_save_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:57:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/01 17:13:47 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_save_file(int fd, t_asm *m_asm)
{
	int		ret;
	char	*line;

	if (((m_asm->file) = ft_list_new()) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_strlen(line) > 0)
			if (ft_list_push_back(m_asm->file, line) < 0)
				return (0);
	}
	if (ret < 0)
	{
		ft_list_apply(m_asm->file, &free);
		ft_list_delete(m_asm->file);
		ft_dprintf(2, "Error while reading file\n");
		return (0);
	}
	return (1);
}
