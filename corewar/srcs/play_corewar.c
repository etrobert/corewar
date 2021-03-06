/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:09:37 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 17:15:20 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static int	main_game(t_corewar *corewar, t_parser *parser)
{
	int		ret;
	int		cycle;

	cycle = 0;
	while (!corewar_end(corewar))
	{
		if (parser->dump_cycle > -1 && cycle == parser->dump_cycle)
		{
			dump_corewar(corewar);
			return (0);
		}
		if ((ret = corewar_advance(corewar) < 0))
			return (-1);
		cycle++;
	}
	return (0);
}

int			play_corewar(t_corewar *corewar, t_list *champs, t_parser *parser)
{
	t_visu	visu;

	if (corewar == NULL)
		return (0);
	if (parser->graphical)
	{
		visu_init(&visu, champs, parser);
		if (init_visu_log(&visu, parser) < 0)
			return (-1);
		corewar_set_fd(corewar, visu.fds[1]);
		return (main_game_visu(corewar, &visu, champs, parser));
	}
	else
	{
		if (init_visu_log(&visu, parser) < 0)
			return (-1);
		if (parser->log_file)
			corewar_set_fd(corewar, visu.fds[1]);
		return (main_game(corewar, parser));
	}
}
