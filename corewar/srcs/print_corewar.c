/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_corewar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2017/02/24 18:41:05 by mverdier         ###   ########.fr       */
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

static void			print_color(t_corewar *corewar, unsigned int pos)
{
	t_list_it		it;
	t_process		*process;

	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		process = (t_process *)ft_list_it_get(corewar->process, it);
		if (process->pc == pos)
		{
			ft_printf("\033[31m");
			return ;
		}
		ft_list_it_inc(&it);
	}
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
	mvwprintw(visu->infos, 10, 10, "process : %d", ft_list_size(corewar->process));
	mvwprintw(visu->infos, 15, 10, "cycle_to_die : %u", corewar->cycles_to_die);
}

static void			print_byte(t_corewar *corewar, unsigned int pos,
		t_visu *visu)
{
	unsigned char	byte;

	byte = corewar_get_byte(corewar, pos);
	wattron(visu->board, COLOR_PAIR(1));
	mvwprintw(visu->board, visu->line, visu->col, "%.2x ", byte);
	wattroff(visu->board, COLOR_PAIR(1));
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
}
