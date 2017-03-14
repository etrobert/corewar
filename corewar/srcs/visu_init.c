/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:02:23 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/13 19:19:48 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	visu_init_colors()
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
	init_color(COLOR_CYAN, 300, 300, 300);
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_pair(9, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
}

static void	visu_init_screens(t_visu *visu, int infos_height)
{
	visu->board = subwin(stdscr, PRINT_WIDTH + 2, 3 * PRINT_WIDTH + 3, 0, 0);
	visu->infos = subwin(stdscr, infos_height, COLS - (3 * PRINT_WIDTH + 3),
			0, 3 * PRINT_WIDTH + 3);
	//visu->log_height = LINES - (PRINT_WIDTH + 4);
	visu->log_height = 15;
	//visu->log = subwin(stdscr, LINES - (PRINT_WIDTH + 2),
	//COLS, PRINT_WIDTH + 2, 0);
	visu->log = subwin(stdscr, PRINT_WIDTH + 2 - infos_height,
			COLS - (3 * PRINT_WIDTH + 3), infos_height, 3 * PRINT_WIDTH + 3);
}

void		visu_init(t_visu *visu)
{
	int		infos_height;
	int		p_number;

	p_number = 4;
	infos_height = 7 + (p_number * 4);
	initscr();
	start_color();
	visu_init_colors();
	visu_init_screens(visu, infos_height);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(0);
	visu->speed = 1000;
	visu->pause = true;
	nodelay(stdscr, 1);
}
