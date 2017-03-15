/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_champ_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:06:31 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/15 20:21:30 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "champion.h"
#include "args_parser.h"
#include <fcntl.h>

static int	open_file(char *filename)
{
	int			fd;
	char		*dot;

	if (ft_strlen(filename) < 4)
	{
		ft_dprintf(2, "Invalid file\n");
		return (-1);
	}
	if ((dot = ft_strrchr(filename, '.')) == NULL)
	{
		ft_dprintf(2, "Invalid file\n");
		return (-1);
	}
	if (ft_strcmp(".cor", dot) != 0)
	{
		ft_dprintf(2, "Invalid file\n");
		return (-1);
	}
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "Failed to open file\n");
		return (-1);
	}
	return (fd);
}

static int	add_champ(t_list **champs, t_champion *champ)
{
	if (*champs == NULL)
	{
		if ((*champs = ft_list_new()) == NULL)
		{
			ft_dprintf(2, "Memory allocation failed\n");
			return (-1);
		}
	}
	if (ft_list_size(*champs) >= MAX_PLAYERS)
	{
		ft_dprintf(2, "Too many champions\n");
		return (-1);
	}
	if (ft_list_push_back(*champs, champ) < 0)
	{
		ft_list_apply(*champs, (t_f_apply)(&champion_delete));
		ft_list_delete(*champs);
		ft_dprintf(2, "Champion initialization failed\n");
		return (-1);
	}
	return (0);
}

int			open_champ_file(t_parser *parser, int champ_id, t_list **champs)
{
	int			fd;
	int			id;
	t_champion	*champ;

	if ((fd = open_file(parser->av[parser->cur_arg])) < 0)
		return (-1);
	if (champ_id == -1)
		id = ++parser->latest_id;
	else
	{
		id = champ_id;
		parser->latest_id = champ_id;
	}
	if ((champ = champion_new()) == NULL)
	{
		ft_dprintf(2, "Failed to create champion\n");
		return (-1);
	}
	if (champion_init(champ, id, fd) < 0)
	{
		ft_dprintf(2, "Champion initialization failed\n");
		return (-1);
	}
	if (add_champ(champs, champ) < 0)
		return (-1);
	return (0);
}
