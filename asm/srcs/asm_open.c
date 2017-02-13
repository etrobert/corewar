/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:49:41 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/13 17:02:43 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"

int		asm_open(char *filename)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "Error while trying to open %s\n", filename);
		return (0);
	}
	return (fd);
}
