/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:55:08 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/05 14:04:37 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"

int		asm_create(char *filename)
{
	int		fd;
	char	*ret;

	ret = ft_strrextract(filename, '.');
	filename = ft_strjoin(ret, ".cor");
	fd = -1;
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		ft_dprintf(2, "Error while trying to create or open %s\n", filename);
	free(ret);
	free(filename);
	return (fd);
}
