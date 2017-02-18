/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:30:00 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/18 20:42:44 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_write_params_bytes(int fd, t_bytes *bytes)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (bytes->param_size[i] == 1)
			write(fd, &(bytes->param[i].c), bytes->param_size[i]);
		else if (bytes->param_size[i] == 2)
			write(fd, &(bytes->param[i].s), bytes->param_size[i]);
		else if (bytes->param_size[i] == 4)
			write(fd, &(bytes->param[i].i), bytes->param_size[i]);
		i++;
	}
}

void		asm_write_bytes(int fd, t_header *header, t_list *instructs)
{
	t_list_it	it;
	t_bytes		*bytes;

	it = ft_list_begin(instructs);
	write(fd, header, sizeof(*header));
	while (!ft_list_it_end(instructs, it))
	{
		bytes = ft_list_it_get(instructs, it);
		write(fd, &(bytes->op_c), bytes->op_c_size);
		write(fd, &(bytes->ocp), bytes->ocp_size);
		asm_write_params_bytes(fd, bytes);
		ft_list_it_inc(&it);
	}
}
