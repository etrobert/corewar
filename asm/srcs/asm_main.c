/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/18 17:46:28 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_init_asm(t_asm *m_asm)
{
	m_asm->file = NULL;
	m_asm->header = NULL;
	m_asm->labels = NULL;
	m_asm->instructs = NULL;
	m_asm->name = false;
	m_asm->comment = false;
	return (1);
}

static int	asm_read(t_asm *m_asm, char *file)
{
	int		fd_in;
	int		ret;

	if ((fd_in = asm_open(file)) < 0)
		return (0);
	ret = asm_save_file(fd_in, m_asm);
	close(fd_in);
	if (!ret)
		return (0);
	if (!asm_get_size(m_asm))
		return (0);
	if (!asm_get_bytes(m_asm))
		return (0);
	return (1);
}

static int	asm_write(t_asm *m_asm, char *file)
{
	int		fd_out;

	if ((fd_out = asm_create(file)) < 0)
		return (0);
	//Peut fail ?
	asm_write_bytes(fd_out, m_asm, file);
	close(fd_out);
	return (1);
}

int			asm_process_file(char *name)
{
	t_asm		m_asm;

	if (!asm_init_asm(&m_asm))
		return (0);
	if (!asm_read(&m_asm, name) || !asm_write(&m_asm, name))
	{
		asm_free_asm(&m_asm);
		return (0);
	}
	asm_free_asm(&m_asm);
	return (1);
}

int			main(int ac, char **av)
{
	int			i;

	if (!asm_usage(ac, av))
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!asm_process_file(av[i]))
			return (-1);
		i++;
	}
	return (0);
}
