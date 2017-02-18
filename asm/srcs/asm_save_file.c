/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_save_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:57:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/18 16:04:39 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_save_file(int fd, t_list **file)
{
	char	*line;
	int		ret;

	if (((*file) = ft_list_new()) == NULL)
		return (0);
	while ((ret = get_next_line(fd, &line)))
		if (ft_list_push_back(*file, line) < 0)
			return (0);
	if (ret < 0)
	{
		ft_list_apply(*file, &free);
		ft_list_delete(*file);
		return (0);
	}
	return (1);
}
