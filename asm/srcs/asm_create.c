/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:55:08 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/13 20:34:18 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"

int		asm_create(char *filename)
{
	int		fd;

	filename = ft_strjoin(ft_strrextract(filename, '.'), ".cor");
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		ft_dprintf(2, "Error while trying to create or open %s\n", filename);
		return (0);
	}
	return (fd);
}
