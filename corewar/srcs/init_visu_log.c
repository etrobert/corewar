/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:43:36 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/21 18:27:24 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

int		init_visu_log(t_visu *visu, t_parser *parser)
{
	int     flags;

	visu->cur_log = -1;
	if (parser->log_file != NULL)
	{
		if (((visu->fds[1] = open(parser->log_file,
			O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) ||
			((visu->fds[0] = open(parser->log_file, O_RDONLY)) < 0))
		{
			ft_dprintf(2, "Failed to open the log file\n");
			return (-1);
		}
	}
	else
	{
		if (pipe(visu->fds) != 0)
		{
			ft_dprintf(2, "Failed to create pipe\n");
			return (-1);
		}
		flags = fcntl(visu->fds[0], F_GETFL, 0);
		fcntl(visu->fds[0], F_SETFL, flags | O_NONBLOCK);
	}
	return (0);
}
