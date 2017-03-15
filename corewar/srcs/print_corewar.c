/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_corewar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:26:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/14 20:33:07 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

//Degueu parcours de la liste de process pour chaque case
static int			print_process(t_corewar *corewar, unsigned int pos,
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
			{
				wattron(visu->board, COLOR_PAIR(id + 4));
				mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
				wattroff(visu->board, COLOR_PAIR(id + 4));
				return (1);
			}
			else
			{
				wattron(visu->board, COLOR_PAIR(9));
				mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
				wattroff(visu->board, COLOR_PAIR(9));
				return (1);
			}
		}
		ft_list_it_inc(&it);
	}
	return (0);
}

static void			print_infos(t_corewar *corewar, t_visu *visu)
{
	int		i;
	int		p;
	int		p_number;
	char	name[] = "Vampire";

	p_number = 4;
	i = 1;
	p = 0;
	if (visu->pause)
		mvwprintw(visu->infos, i++, 2, "PAUSED");
	else
		mvwprintw(visu->infos, i++, 2, "PLAY");
	if (visu->speed == 0)
		mvwprintw(visu->infos, i++, 2, "speed limit : %u cycles/s", 1000);
	else
		mvwprintw(visu->infos, i++, 2, "speed limit : %u cycles/s", 1000000 /
				visu->speed);
	mvwprintw(visu->infos, i++, 2, "cycle : %u", corewar->cycle);
	mvwprintw(visu->infos, i++, 2, "process : %d",
			ft_list_size(corewar->process));
	mvwprintw(visu->infos, i++, 2, "cycle_to_die : %u", corewar->cycles_to_die);
	i++;
	while (p < p_number)
	{
		mvwprintw(visu->infos, i, 2, "Player %d : ", p_number);
		wattron(visu->infos, COLOR_PAIR(p_number));
		mvwprintw(visu->infos, i++, 13, "%s", name);
		wattroff(visu->infos, COLOR_PAIR(p_number));
		mvwprintw(visu->infos, i++, 2, "Last live :               %d",
				corewar->cycle);
		mvwprintw(visu->infos, i++, 2, "Lives in current period : %d",
				corewar->cycle);
		i++;
		p++;
	}
}

static void			print_byte(t_corewar *corewar, unsigned int pos,
		t_visu *visu)
{
	unsigned char	byte;
	t_id_type		id;

	byte = corewar_get_byte(corewar, pos);
	if (!print_process(corewar, pos, visu, byte))
	{
		if ((id = corewar_get_byte_id(corewar, pos)) != 0)
		{
			wattron(visu->board, COLOR_PAIR(id));
			mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
			wattroff(visu->board, COLOR_PAIR(id));
		}
		else
		{
			wattron(visu->board, COLOR_PAIR(10));
			mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
			wattroff(visu->board, COLOR_PAIR(10));
		}
	}
}

void				print_corewar(t_corewar *cw, t_visu *visu)
{
	unsigned int	i;
	unsigned int	j;

	print_infos(cw, visu);
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
