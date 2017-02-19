/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/19 21:25:41 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_fds			fd;
	t_list			*file;
	t_header		*header;
	t_list			*labels;
	t_list			*instructs;

	if (!asm_usage(ac, av))
		return (0);
	if ((fd.in = asm_open(av[1])) < 0)
		return (-1);
	if (!asm_save_file(fd.in, &file))
		return (-1);
	if (!asm_get_size(&header, &labels, file))
		return (-1);
	if (!asm_get_bytes(&instructs, labels, file))
		return (-1);
	if ((fd.out = asm_create(av[1])) < 0)
		return (-1);
	asm_write_bytes(fd.out, header, instructs);
	close(fd.out);
	close(fd.in);
	free(header);
	return (0);
}
