/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/14 17:04:38 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	int				fd_out;
	int				fd_in;
	t_header		*header;

	if (!asm_usage(ac, av))
		return (0);
	if (!(fd_in = asm_open(av[1])) || !(fd_out = asm_create(av[1])))
		return (-1);
	if ((header = asm_get_header(fd_in)) == NULL)
		return (-1);
	write(fd_out, header, sizeof(*header));
	close(fd_out);
	close(fd_in);
	free(header);
	return (0);
}