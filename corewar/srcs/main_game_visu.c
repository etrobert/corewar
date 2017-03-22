/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game_visu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:40:06 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 14:40:04 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void	visu_resize(t_visu *visu, t_list *champs)
{
	int		infos_height;
	size_t	p_number;

	p_number = ft_list_size(champs);
	infos_height = 7 + (p_number * 4);
	visu->board = subwin(stdscr, BOARD_HEIGHT, BOARD_WIDTH, 0, 0);
	visu->infos = subwin(stdscr, infos_height, INFOS_WIDTH,
			0, INFOS_X);
	visu->log_height = PRINT_WIDTH - infos_height - 2;
	visu->log_border = subwin(stdscr, BOARD_HEIGHT - infos_height,
			INFOS_WIDTH, infos_height, INFOS_X);
	box(visu->log_border, ACS_VLINE, ACS_HLINE);
}

static void	print_round(t_visu *visu, t_corewar *corewar, t_list *champs)
{
	visu_resize(visu, champs);
	werase(visu->board);
	werase(visu->infos);
	box(visu->board, ACS_VLINE, ACS_HLINE);
	box(visu->infos, ACS_VLINE, ACS_HLINE);
	box(visu->log_border, ACS_VLINE, ACS_HLINE);
	print_corewar(corewar, visu, champs);
	print_log(visu);
	wrefresh(visu->board);
	wrefresh(visu->infos);
	wrefresh(visu->log);
	wrefresh(visu->log_border);
}

static void	sleep_game(t_visu *visu, struct timeval begin)
{
	struct timeval	end;
	unsigned int	time;

	gettimeofday(&end, NULL);
	if ((time = end.tv_usec - begin.tv_usec) > visu->speed)
		usleep(0);
	else
		usleep(visu->speed);
}

int			main_game_visu(t_corewar *corewar, t_visu *visu, t_list *champs)
{
	int				ret;
	int				play;
	struct timeval	begin;

	while ((play = play_events(visu)) == 0)
	{
		gettimeofday(&begin, NULL);
		print_round(visu, corewar, champs);
		if (!corewar_end(corewar) && !visu->pause &&
				(ret = corewar_advance(corewar)) < 0)
		{
			visu_end(visu);
			return (ret);
		}
		sleep_game(visu, begin);
	}
	return (0);
}
