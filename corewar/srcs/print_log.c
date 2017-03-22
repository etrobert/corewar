/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:33:57 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 14:38:29 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void	update_log(t_visu *visu, char **lines)
{
	int			i;

	i = 0;
	while (lines[i] != NULL)
	{
		if (visu->cur_log > visu->log_height)
			wscrl(visu->log, 1);
		else
			++visu->cur_log;
		if (ft_strlen(lines[i]) - 3 > (unsigned long)INFOS_WIDTH - 1)
			mvwprintw(visu->log, visu->cur_log, 0, "%.*s...",
					INFOS_WIDTH - 5, lines[i]);
		else
			mvwprintw(visu->log, visu->cur_log, 0, "%s", lines[i]);
		free(lines[i]);
		++i;
	}
}

static int	get_buf(char **log_buf, int fd)
{
	char	buf[128];
	size_t	len;
	int		ret;

	if ((*log_buf = ft_strnew(0)) == NULL)
		return (-1);
	len = 0;
	while ((ret = read(fd, buf, 128)) > 0)
	{
		if (!(*log_buf = ft_nrealloc(*log_buf, len + 1, len + 1 + ret)))
			return (-1);
		ft_memmove(*log_buf + len, buf, ret);
		len += ret;
		(*log_buf)[len] = '\0';
	}
	if (ret == -1 && (errno != EAGAIN))
	{
		free(*log_buf);
		return (-1);
	}
	return (0);
}

int			print_log(t_visu *visu)
{
	char	*log_buf;
	char	**log_lines;

	log_buf = NULL;
	if (get_buf(&log_buf, visu->fds[0]) != 0)
		return (-1);
	log_lines = ft_strsplit(log_buf, '\n');
	free(log_buf);
	update_log(visu, log_lines);
	free(log_lines);
	return (0);
}
