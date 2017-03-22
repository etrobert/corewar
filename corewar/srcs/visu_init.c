/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:02:23 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 17:22:02 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void	visu_init_colors(void)
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
	init_color(COLOR_WHITE, 700, 700, 700);
	init_pair(9, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
}

static void	visu_init_screens(t_visu *visu, int infos_height, t_parser *parser)
{
	visu->board = subwin(stdscr, BOARD_HEIGHT, BOARD_WIDTH, 0, 0);
	if (parser->console)
	{
		visu->infos = subwin(stdscr, infos_height, INFOS_WIDTH,
				0, INFOS_X);
		visu->log_height = PRINT_WIDTH - infos_height - 2;
		visu->log_border = subwin(stdscr, BOARD_HEIGHT - infos_height,
				INFOS_WIDTH, infos_height, INFOS_X);
		box(visu->log_border, ACS_VLINE, ACS_HLINE);
		visu->log = subwin(stdscr, BOARD_HEIGHT - 2 - infos_height,
				INFOS_WIDTH - 2, infos_height + 1, INFOS_X + 1);
		scrollok(visu->log, TRUE);
	}
	else
		visu->infos = subwin(stdscr, BOARD_HEIGHT, INFOS_WIDTH,
				0, INFOS_X);
	return ;
}

void		visu_init(t_visu *visu, t_list *champs, t_parser *parser)
{
	int		infos_height;
	size_t	p_number;

	p_number = ft_list_size(champs);
	infos_height = 7 + (p_number * 4);
	initscr();
	start_color();
	visu_init_colors();
	visu_init_screens(visu, infos_height, parser);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(0);
	visu->speed = 20000;
	visu->pause = true;
	nodelay(stdscr, 1);
}
