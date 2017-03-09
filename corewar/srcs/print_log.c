/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:33:57 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/09 20:25:25 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int	update_log(t_visu *visu)
{
	int			i;
	t_list_it	it;
	char		*line_str;

	i = 0;
	it = ft_list_begin(visu->log_lines);
	while (!ft_list_it_end(visu->log_lines, it))
	{
		line_str = (char*)ft_list_it_get(visu->log_lines, it);
		if (mwprintw(visu->log, i, 0, "%s", line_str) == ERR)
			return (-1);
		++i;
	}
	return (0);
}

static int	get_buf(char **log_buf, int fd)
{
	char	buf[8];
	size_t	len;

	*log_buf = ft_strnew(8);
	len = 8;
	while (ret > 0)
	{
		ret = read(fd, buf, 8);
		if (ret == -1)
			return ((errno == EAGAIN) ? 0 : -1);
		if (ret == 0)
			return (0);
		buf[ret] = 0;
		if (!(*log_buf = ft_nrealloc(*log_buf, len + 1, len + 1 + ret)))
			return (-1);
		ft_memcpy(*log_buf + len, buf, ret);
		len += ret;
		(*log_buf)[len] = '\0';
	}
	return (0);
}

static int	add_log_lines(t_visu *visu, char **lines)
{
	int			i;

	i = 0;
	while (lines[i] != NULL)
	{
		if (ft_list_size(visu->log_lines) == visu->log_height)
		{
			free(ft_list_front(visu->log_lines));
			ft_list_pop_front(visu->log_lines);
		}
		if (ft_list_push_back(visu->log_lines, lines[i]) == -1)
		{
			while (lines[i] != NULL)
			{
				free(lines[i]);
				++i;
			}
			return (-1);
		}
		++i;
	}
}

int			print_log(t_corewar *corewar, t_visu *visu)
{
	char	*log_buf;
	char	**log_lines;
	int		ret;

	log_buf = NULL;
	if (get_buf(&log_buf, visu->fds[0]) != 0)
		return (-1);
	log_lines = ft_strsplit('\n', log_buf);
	free(log_buf);
	if (add_log_lines(visu, log_line) == -1)
	{
		ft_list_apply(visu->log_lines, &free);
		return (-1);
	}
	if (update_log(visu)
	return (0);
}
