/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_save_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:57:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/25 16:59:20 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_save_file(int fd, t_asm *m_asm)
{
	int		ret;
	char	*line;

	if (((m_asm->file) = ft_list_new()) == NULL)
		return (0);
	// test gnl == -1
	while ((ret = get_next_line(fd, &line)))
		if (ft_list_push_back(m_asm->file, line) < 0)
			return (0);
	if (ret < 0)
	{
		ft_list_apply(m_asm->file, &free);
		ft_list_delete(m_asm->file);
		return (0);
	}
	return (1);
}
