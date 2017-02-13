/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:29:36 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/13 20:34:13 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"

t_header	asm_get_header(int fd)
{
	char		*line;
	t_header	header;

	ft_bzero(header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(header.comment, COMMENT_LENGTH + 1);
	header.magic = ft_int32_big_endian(COREWAR_EXEC_MAGIC);
	header.prog_size = ft_int32_big_endian(23);
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, NAME_CMD_STRING))
			ft_memmove(header.prog_name, ft_strchr(line, '"') + 1,
						ft_strrchr(line, '"') - (ft_strchr(line, '"') + 1));
		if (ft_strstr(line, COMMENT_CMD_STRING))
			ft_memmove(header.comment, ft_strchr(line, '"') + 1,
						ft_strrchr(line, '"') - (ft_strchr(line, '"') + 1));
		free(line);
	}
	return (header);
}
