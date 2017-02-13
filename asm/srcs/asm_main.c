/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/12 20:20:38 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_errors.h"
#include "ft_strrextract.h"

#include <fcntl.h>
#include <unistd.h>

static unsigned int	to_big_endian(unsigned int magic)
{
	unsigned int	res;

	res = (magic & 0x000000ff) << 24 | (magic & 0x0000ff00) << 8 |
		(magic & 0x00ff0000) >> 8 | (magic & 0xff000000) >> 24;
	return (res);
}

int		main(int ac, char **av)
{
	char			*out;
	int				fd_cor;
	int				fd_s;
	t_header		header;

	if (!asm_usage(ac, av))
		return (0);
	if ((fd_s = open(av[1], O_RDONLY)) < 0)
		return (asm_error_open(av[1]));
	out = ft_strjoin(ft_strrextract(av[1], '.'), ".cor");
	if ((fd_cor = open(out, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		return (asm_error_create(out));
	header.magic = to_big_endian(COREWAR_EXEC_MAGIC);
	write(fd_cor, &header.magic, sizeof(header.magic));
	close(fd_cor);
	close(fd_s);
	return (0);
}
