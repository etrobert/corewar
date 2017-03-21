/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game_visu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:40:06 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/21 15:40:27 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void	print_round(t_visu *visu, t_corewar *corewar, t_list *champs)
{
	erase();
	box(visu->board, ACS_VLINE, ACS_HLINE);
	box(visu->infos, ACS_VLINE, ACS_HLINE);
	box(visu->log, ACS_VLINE, ACS_HLINE);
	print_corewar(corewar, visu, champs);
//	print_log(visu);
	refresh();
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
