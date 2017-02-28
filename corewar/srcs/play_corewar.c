/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:09:37 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/28 11:23:51 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"

static void	print_init_visu(t_visu *visu)
{
	initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	visu->board = subwin(stdscr, PRINT_WIDTH + 2, 3 * PRINT_WIDTH + 2, 0, 0);
	visu->infos = subwin(stdscr, PRINT_WIDTH + 2, COLS - (3 * PRINT_WIDTH + 2),
			0, 3 * PRINT_WIDTH + 2);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	nodelay(stdscr, 0);
}

static void print_round(t_visu *visu, t_corewar *corewar)
{
	werase(visu->board);
	werase(visu->infos);
	box(visu->board, ACS_VLINE, ACS_HLINE);
	box(visu->infos, ACS_VLINE, ACS_HLINE);
	print_corewar(corewar, visu);
	wrefresh(visu->board);
	wrefresh(visu->infos);
}

static void	print_end()
{
	while (getch() != 27)
	{
	}
	endwin();
}

int	play_corewar(t_corewar *corewar)
{
	int				ret;
	t_visu			visu;

	if (corewar == NULL)
		return (0);
	print_init_visu(&visu);
	while (!corewar_end(corewar))
	{
		print_round(&visu, corewar);
		if ((ret = corewar_advance(corewar)) < 0)
		{
			print_end();
			return (ret);
		}
	}
	print_end();
	return (0);
}
