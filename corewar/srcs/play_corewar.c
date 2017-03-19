/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:09:37 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/19 18:54:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

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

static int	main_game_visu(t_corewar *corewar, t_visu *visu, t_list *champs)
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

static int	main_game(t_corewar *corewar)
{
	int		ret;

	while (!corewar_end(corewar))
		if ((ret = corewar_advance(corewar) < 0))
			return (-1);
	return (0);
}

int			play_corewar(t_corewar *corewar, t_list *champs, t_parser *parser)
{
	t_visu	visu;

	if (corewar == NULL)
		return (0);
	if (parser->graphical)
	{
		visu_init(&visu, champs);
		//		init_visu_log(&visu);
		//		corewar_set_fd(corewar, visu.fds[1]);
		corewar_set_fd(corewar, 2);
		return (main_game_visu(corewar, &visu, champs));
	}
	else
		return (main_game(corewar));
}
