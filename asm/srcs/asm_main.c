/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/05 17:17:21 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_init_asm(t_asm *m_asm)
{
	if ((m_asm = (t_asm*)malloc(sizeof(t_asm))) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	m_asm->file = NULL;
	m_asm->header = NULL;
	m_asm->labels = NULL;
	m_asm->instructs = NULL;
	return (1);
}

static int	asm_close(t_fds fd)
{
	if (close(fd.out) < 0 || close(fd.in) < 0)
	{
		ft_dprintf(2, "Error on closing files\n");
		return (0);
	}
	return (1);
}

static int	asm_read(t_fds *fd, t_asm *m_asm, char *file)
{
	if ((fd->in = asm_open(file)) < 0)
		return (0);
	if (!asm_save_file(fd->in, m_asm))
		return (0);
	if (!asm_get_size(m_asm))
		return (0);
	if (!asm_get_bytes(m_asm))
		return (0);
	return (1);
}

static int	asm_write(t_fds *fd, t_asm m_asm, char *file)
{
	if ((fd->out = asm_create(file)) < 0)
		return (0);
	asm_write_bytes(fd->out, m_asm, file);
	return (1);
}

int			main(int ac, char **av)
{
	t_fds			fd;
	t_asm			m_asm;

	if (!asm_usage(ac, av))
		return (0);
	if (!asm_init_asm(&m_asm))
		return (-1);
	if (!asm_read(&fd, &m_asm, av[1]))
		return (-1);
	if (!asm_write(&fd, m_asm, av[1]))
		return (-1);
	if (!asm_close(fd))
		return (-1);
	return (0);
}
