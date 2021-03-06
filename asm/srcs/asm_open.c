/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:49:41 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/18 16:43:57 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_open(char *filename)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "Error while trying to open %s\n", filename);
		return (-1);
	}
	return (fd);
}
