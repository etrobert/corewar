/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_save_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:57:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 16:39:10 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_save_file(int fd, t_list **file)
{
	char	*line;

	if (((*file) = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (0);
	while (get_next_line(fd, &line))
		if (ft_list_push_back(*file, line) < 0)
			return (0);
	return (1);
}
