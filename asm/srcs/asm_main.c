/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/28 11:47:05 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_init_asm(t_asm *m_asm)
{
	if ((m_asm = (t_asm*)malloc(sizeof(t_asm))) == NULL)
		return (0);
	m_asm->file = NULL;
	m_asm->header = NULL;
	m_asm->labels = NULL;
	m_asm->instructs = NULL;
	return (1);
}

static void	asm_close(t_fds fd, int *ret)
{
	if (close(fd.out) < 0 || close(fd.in) < 0)
	{
		ft_dprintf(2, "Error on closing files");
		*ret = -1;
	}
}

int			main(int ac, char **av)
{
	t_fds			fd;
	t_asm			m_asm;
	int				ret;

	ret = 0;
	if (!asm_usage(ac, av))
		return (0);
	if (!asm_init_asm(&m_asm))
		return (-1);
	if ((fd.in = asm_open(av[1])) < 0)
		return (-1);
	if (!asm_save_file(fd.in, &m_asm))
		return (-1);
	if (!asm_get_size(&m_asm))
		return (-1);
	if (!asm_get_bytes(&m_asm))
		return (-1);
	if ((fd.out = asm_create(av[1])) < 0)
		return (-1);
	asm_write_bytes(fd.out, m_asm);
	asm_close(fd, &ret);
	return (0);
}
