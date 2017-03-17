/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:02:23 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/16 19:50:13 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	visu_init_colors()
{
/*	init_color(DGREEN, 0, 700, 0);
	init_color(LGREEN, 0, 1000, 0);
	init_color(DRED, 700, 0, 0);
	init_color(LRED, 1000, 0, 0);
	init_color(DBLUE, 0, 0, 700);
	init_color(LBLUE, 0, 0, 1000);
	init_color(DORANGE, 1000, 700, 0);
	init_color(LORANGE, 1000, 500, 0);*/
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
	init_color(COLOR_WHITE, 700, 700, 700);
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

void		visu_init(t_visu *visu, t_list *champs)
{
	int		infos_height;
	size_t	p_number;

	p_number = ft_list_size(champs);
	infos_height = 7 + (p_number * 4);
	initscr();
	start_color();
//	use_default_colors();
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
