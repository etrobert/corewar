/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 17:30:34 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_fd			fd;
	t_header		*header;
	t_list			*file;

	header = NULL;
	if (!asm_usage(ac, av))
		return (0);
	if (!(fd.in = asm_open(av[1])) || !(fd.out = asm_create(av[1])))
		return (-1);
	if (!asm_save_file(fd.in, &file))
		return (-1);
	if (!asm_parse(&header, file))
		return (-1);
	write(fd.out, header, sizeof(*header));
	close(fd.out);
	close(fd.in);
	free(header);
	return (0);
}
