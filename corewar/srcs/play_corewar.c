/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:09:37 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/14 19:53:11 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"

#include <sys/time.h>

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

static void	print_round(t_visu *visu, t_corewar *corewar)
{
	werase(visu->board);
	werase(visu->infos);
	werase(visu->log);
	box(visu->board, ACS_VLINE, ACS_HLINE);
	box(visu->infos, ACS_VLINE, ACS_HLINE);
	box(visu->log, ACS_VLINE, ACS_HLINE);
	print_corewar(corewar, visu);
//	print_log(visu);
	wrefresh(visu->board);
	wrefresh(visu->infos);
	wrefresh(visu->log);
}

static int	main_game(t_corewar *corewar, t_visu *visu)
{
	int				ret;
	int				play;
	unsigned int	time;
	struct timeval	begin;
	struct timeval	end;

	while ((play = play_events(visu)) != 0)
	{
		gettimeofday(&begin, NULL);
		print_round(visu, corewar);
		if (!corewar_end(corewar) && !visu->pause &&
				(ret = corewar_advance(corewar)) < 0)
		{
			visu_end(visu);
			return (ret);
		}
		gettimeofday(&end, NULL);
		if ((time = end.tv_usec - begin.tv_usec) > visu->speed)
			usleep(0);
		else
			usleep(visu->speed);
	}
	if (play == 0)
		return (-1);
	return (0);
}

int			play_corewar(t_corewar *corewar)
{
	int				ret;
	t_visu			visu;

	if (corewar == NULL)
		return (0);
	visu_init(&visu);
//	init_visu_log(&visu);
//	corewar_set_fd(corewar, visu.fds[1]);
	corewar_set_fd(corewar, 2);
	if ((ret = main_game(corewar, &visu)) < 0)
		return (ret);
	return (0);
}
