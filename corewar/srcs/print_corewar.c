/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_corewar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:26:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 15:05:33 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static int		print_process(t_corewar *corewar, unsigned int pos,
		t_visu *visu, unsigned char byte)
{
	t_list_it		it;
	t_id_type		id;
	t_process		*process;

	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		process = (t_process *)ft_list_it_get(corewar->process, it);
		if (process->pc == pos)
		{
			if ((id = corewar_get_byte_id(corewar, pos)) != 0)
				id = id + 4;
			else
				id = 9;
			wattron(visu->board, COLOR_PAIR(id));
			mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
			wattroff(visu->board, COLOR_PAIR(id));
			return (1);
		}
		ft_list_it_inc(&it);
	}
	return (0);
}

static void		print_byte(t_corewar *corewar, unsigned int pos,
		t_visu *visu)
{
	unsigned char	byte;
	t_id_type		id;

	byte = corewar_get_byte(corewar, pos);
	if (!print_process(corewar, pos, visu, byte))
	{
		if ((id = corewar_get_byte_id(corewar, pos)) == 0)
			id = 10;
		wattron(visu->board, COLOR_PAIR(id));
		mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
		wattroff(visu->board, COLOR_PAIR(id));
	}
}

void			print_corewar(t_corewar *cw, t_visu *visu, t_list *champs)
{
	unsigned int	i;
	unsigned int	j;

	print_infos(cw, visu, champs);
	visu->line = 1;
	j = 0;
	while (j * PRINT_WIDTH < MEM_SIZE)
	{
		visu->col = 2;
		i = 0;
		while (i < PRINT_WIDTH && j * PRINT_WIDTH + i < MEM_SIZE)
		{
			print_byte(cw, j * PRINT_WIDTH + i, visu);
			i++;
			visu->col += 3;
		}
		j++;
		(visu->line)++;
	}
}
