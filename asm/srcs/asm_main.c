/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:09 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/25 16:07:40 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*static void	print_labels(t_list *labels)
{
	t_list_it	it;
	t_labels	*label;

	it = ft_list_begin(labels);
	label = ft_list_it_get(labels, it);
	while (!ft_list_it_end(labels, it))
	{
		ft_printf("name = %s\n", label->name);
		ft_printf(" pos = %u\n\n", label->position);
		ft_list_it_inc(&it);
		label = ft_list_it_get(labels, it);
	}
}*/

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

int			main(int ac, char **av)
{
	t_fds			fd;
	t_asm			m_asm;

	if (!asm_init_asm(&m_asm))
		return (-1);
	if (!asm_usage(ac, av))
		return (0);
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
	close(fd.out);
	close(fd.in);
	return (0);
}
