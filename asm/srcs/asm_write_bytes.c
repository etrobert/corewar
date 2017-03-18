/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:30:00 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/11 20:36:29 by mverdier         ###   ########.fr       */
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

void		asm_write_bytes(int fd, t_asm *m_asm, char *filename)
{
	t_list_it	it;
	t_bytes		*bytes;
	char		*ret;

	ret = ft_strrextract(filename, '.');
	filename = ft_strjoin(ret, ".cor");
	ft_printf("Writing output program to %s\n", filename);
	it = ft_list_begin(m_asm->instructs);
	write(fd, m_asm->header, sizeof(t_header));
	while (!ft_list_it_end(m_asm->instructs, it))
	{
		bytes = ft_list_it_get(m_asm->instructs, it);
		write(fd, &(bytes->op_tab->op_code), 1);
		write(fd, &(bytes->ocp), bytes->ocp_size);
		asm_write_params_bytes(fd, bytes);
		ft_list_it_inc(&it);
	}
	free(ret);
	free(filename);
}
