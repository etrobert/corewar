/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:03:46 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 14:29:05 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static bool		int_good_size(void)
{
	return (sizeof(unsigned int) == 4);
}

int				init_game(t_corewar **cw, t_parser **parser, t_list **champs)
{
	if (!int_good_size())
	{
		ft_dprintf(2, "This system is not supported.\n");
		return (0);
	}
	if (parse_args(*parser, champs) < 0)
	{
		free_params(*champs, *cw, *parser);
		return (-1);
	}
	if (*champs == NULL || ft_list_size(*champs) < 1)
	{
		ft_dprintf(2, "No champions loaded\n");
		free_params(*champs, *cw, *parser);
		return (-1);
	}
	if (!(*parser)->graphical)
		print_champs(*champs);
	if ((*cw = corewar_new(*champs, 2)) == NULL)
	{
		ft_dprintf(2, "Error creating corewar\n");
		free_params(*champs, *cw, *parser);
		return (-1);
	}
	return (0);
}
