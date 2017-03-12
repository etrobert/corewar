/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:09:37 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/11 21:54:30 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"

int			init_visu_log(t_visu *visu)
{
	int		flags;

	if (pipe(visu->fds) != 0)
		return (-1);
	flags = fcntl(visu->fds[0], F_GETFL, 0);
	fcntl(visu->fds[0], F_SETFL, flags | O_NONBLOCK);
	if ((visu->log_lines = ft_list_new()) == NULL)
	{
		close(visu->fds[0]);
		close(visu->fds[1]);
		return (-1);
	}
	return (0);
}

static void	print_init_visu(t_visu *visu)
{
	initscr();
	start_color();
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
	visu->board = subwin(stdscr, PRINT_WIDTH + 2, 3 * PRINT_WIDTH + 2, 0, 0);
	visu->infos = subwin(stdscr, PRINT_WIDTH + 2 - 17, COLS - (3 * PRINT_WIDTH + 2),
			0, 3 * PRINT_WIDTH + 2);
	//visu->log_height = LINES - (PRINT_WIDTH + 4);
	visu->log_height = 15;
	//visu->log = subwin(stdscr, LINES - (PRINT_WIDTH + 2), COLS, PRINT_WIDTH + 2, 0);
	visu->log = subwin(stdscr, 17, COLS - (3 * PRINT_WIDTH + 2), PRINT_WIDTH + 2 - 17, 3 * PRINT_WIDTH + 2);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(0);
	visu->speed = 10000;
	visu->pause = true;
	nodelay(stdscr, 1);
}

static void	print_round(t_visu *visu, t_corewar *corewar)
{
	werase(visu->board);
	werase(visu->infos);
	werase(visu->log);
	box(visu->board, ACS_VLINE, ACS_HLINE);
	box(visu->infos, ACS_VLINE, ACS_HLINE);
	box(visu->log, ACS_VLINE, ACS_HLINE);
	print_corewar(corewar, visu);
	print_log(visu);
	wrefresh(visu->board);
	wrefresh(visu->infos);
	wrefresh(visu->log);
	usleep(visu->speed);
}

static void	print_end(void)
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
	init_visu_log(&visu);
	corewar_set_fd(corewar, visu.fds[1]);
	while (!corewar_end(corewar))
	{
		print_round(&visu, corewar);
		if (!visu.pause && (ret = corewar_advance(corewar)) < 0)
		{
			print_end();
			return (ret);
		}
		if (!play_events(&visu))
			return (0);
	}
	print_end();
	return (0);
}
