/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:30:00 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/19 15:43:06 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_write_params_bytes(int fd, t_bytes *bytes)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (bytes->param_size[i] == 1)
		{
			if (write(fd, &(bytes->param[i].c), bytes->param_size[i]) < 0)
				return (0);
		}
		else if (bytes->param_size[i] == 2)
		{
			if (write(fd, &(bytes->param[i].s), bytes->param_size[i]) < 0)
				return (0);
		}
		else if (bytes->param_size[i] == 4)
		{
			if (write(fd, &(bytes->param[i].i), bytes->param_size[i]) < 0)
				return (0);
		}
		i++;
	}
	return (1);
}

static void	asm_free_temps(char **ret, char **filename)
{
	free(*ret);
	free(*filename);
}

static int	asm_write_champ(int fd, t_asm *m_asm)
{
	t_bytes		*bytes;
	t_list_it	it;

	it = ft_list_begin(m_asm->instructs);
	while (!ft_list_it_end(m_asm->instructs, it))
	{
		bytes = ft_list_it_get(m_asm->instructs, it);
		if (write(fd, &(bytes->op_tab->op_code), 1) < 0||
				write(fd, &(bytes->ocp), bytes->ocp_size) < 0||
				!asm_write_params_bytes(fd, bytes))
			return (0);
		ft_list_it_inc(&it);
	}
	return (1);
}

int			asm_write_bytes(int fd, t_asm *m_asm, char *filename)
{
	char		*ret;

	ret = ft_strrextract(filename, '.');
	filename = ft_strjoin(ret, ".cor");
	ft_printf("Writing output program to %s\n", filename);
	if (write(fd, m_asm->header, sizeof(t_header)) < 0)
	{
		asm_free_temps(&ret, &filename);
		return (0);
	}
	if (!asm_write_champ(fd, m_asm))
	{
		asm_free_temps(&ret, &filename);
		return (0);
	}
	asm_free_temps(&ret, &filename);
	return (1);
}
