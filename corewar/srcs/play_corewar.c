/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:09:37 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/13 19:23:52 by mverdier         ###   ########.fr       */
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
	usleep(visu->speed);
}

static int	main_game(t_corewar *corewar, t_visu *visu)
{
	int		ret;

	while (!corewar_end(corewar))
	{
		print_round(visu, corewar);
		if (!visu->pause && (ret = corewar_advance(corewar)) < 0)
		{
			visu_end(visu);
			return (ret);
		}
		if (!play_events(visu))
			return (0);
	}
	return (1);
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
	if ((ret = main_game(corewar, &visu)) != 1)
		return (ret);
	while (play_events(&visu))
	{
	}
	return (0);
}
