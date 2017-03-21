/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:43:36 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/21 15:02:11 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

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
