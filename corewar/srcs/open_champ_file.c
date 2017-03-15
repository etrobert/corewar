/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_champ_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:06:31 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/15 18:06:54 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "champion.h"

static int	open_file(char *filename)
{
	if (ft_strlen(filename) < 4)
	{
		ft_dprintf(2, "Invalid file");
		return (-1);
	}
	if ((dot = ft_strrchr(filename, '.')) == NULL)
	{
		ft_dprintf(2, "Invalid file");
		return (-1);
	}
	if (ft_strcmp(".cor", dot) != 0)
	{
		ft_dprintf(2, "Invalid file");
		return (-1);
	}
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "Failed to open file");
		return (-1);
	}

	return (0);
}

int	open_champ_file(t_parser *parser, int champ_id, t_list *champs)
{
	int			id;
	int			fd;
	char		*dot;
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
	if (champion_init(champ, id, fd) < 0)
	{
		ft_dprintf(2, "Champion initialization failed");
		return (-1);
	}
	if (ft_list_push_back(champs, champ) < 0)
	{
		ft_list_apply(champs, &ft_champion_delete);
		ft_list_delete(champs);
		ft_dprintf(2, "Champion initialization failed");
		return (-1);
	}
	return (0);
}
