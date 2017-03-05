/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_corewar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:26:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/05 20:17:51 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

/*static void			print_line(void)
{
	int				i;

	i = 0;
	while (i < PRINT_WIDTH)
	{
		ft_printf("-- ");
		++i;
	}
	ft_putchar('\n');
}

static void			print_byte_color(t_corewar *corewar, unsigned int pos)
{
	t_id_type		id;

	if ((id = corewar_get_byte_id(corewar, pos)) != 0)
		ft_printf("%d", 30 + id);
	else
		ft_printf("39");
}

//Degueu parcours de la liste de process pour chaque case
static void			print_color(t_corewar *corewar, unsigned int pos)
{
	t_list_it		it;
	t_process		*process;

	ft_printf("\033[");
	print_byte_color(corewar, pos);
	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		process = (t_process *)ft_list_it_get(corewar->process, it);
		if (process->pc == pos)
		{
			ft_printf(";100m");
			return ;
		}
		ft_list_it_inc(&it);
	}
	ft_printf("m");
}

static void			reset_color(void)
{
	ft_printf("\033[0m");
}*/

/*void				old_print_corewar(t_corewar *cw)
{
	unsigned int	i;
	unsigned int	j;

	print_line();
	j = 0;
	while (j * PRINT_WIDTH < MEM_SIZE)
	{
		i = 0;
		while (i < PRINT_WIDTH && j * PRINT_WIDTH + i < MEM_SIZE)
		{
			print_byte(cw, j * PRINT_WIDTH + i);
			++i;
		}
		ft_printf("\n");
		++j;
	}
	print_line();
}*/

static void			print_infos(t_corewar *corewar, t_visu *visu)
{
	mvwprintw(visu->infos, 5, 10, "cycle : %u", corewar->cycle);
	mvwprintw(visu->infos, 10, 10, "process : %d",
			ft_list_size(corewar->process));
	mvwprintw(visu->infos, 15, 10, "cycle_to_die : %u", corewar->cycles_to_die);
}

static void			print_byte(t_corewar *corewar, unsigned int pos,
		t_visu *visu)
{
	unsigned char	byte;
	t_id_type		id;

	byte = corewar_get_byte(corewar, pos);
	if (pos == visu->pos)
	{
		wattron(visu->board, COLOR_PAIR(5));
		mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
		wattroff(visu->board, COLOR_PAIR(5));
	}
	else
	{
		if ((id = corewar_get_byte_id(corewar, pos)) != 0)
		{
			wattron(visu->board, COLOR_PAIR(id));
			mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
			wattroff(visu->board, COLOR_PAIR(id));
		}
		else
		{
			wattron(visu->board, COLOR_PAIR(6));
			mvwprintw(visu->board, visu->line, visu->col, "%.2x", byte);
			wattroff(visu->board, COLOR_PAIR(6));
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
		visu->col = 1;
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
	(visu->pos)++;
	if (visu->pos == MEM_SIZE)
		visu->pos = 0;
}
