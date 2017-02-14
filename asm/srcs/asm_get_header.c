/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:29:36 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/14 17:19:21 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_header	*asm_get_header(int fd)
{
	char		*line;
	t_header	*header;

	if ((header = (t_header*)malloc(sizeof(t_header))) == NULL)
	{
		ft_dprintf(2, "Malloc error.\n");
		return (NULL);
	}
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 2);
	ft_bzero(header->comment, COMMENT_LENGTH + 2);
	header->magic = ft_int32_big_endian(COREWAR_EXEC_MAGIC);
	header->prog_size = ft_int32_big_endian(23);
	while (get_next_line(fd, &line))
	{
			if (!asm_get_prog_name(line, header))
				return (0);
			if (!asm_get_prog_comment(line, header))
				return (0);
		free(line);
	}
	return (header);
}
