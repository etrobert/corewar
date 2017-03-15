/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:57:55 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/14 21:04:34 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "champion.h"

int	process_file(char *filename, int champ_id, t_list *champs)
{
	char		*dot;
	t_champion	*champ;

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
	if (champion_init(champ, champ_id, fd) < 0)
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
