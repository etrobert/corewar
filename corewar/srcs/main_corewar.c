/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:40:53 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/22 17:27:30 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

int					main_corewar(int argc, char **argv)
{
	t_list		*champs;
	t_corewar	*cw;
	t_parser	*parser;
	int			ret;

	champs = NULL;
	parser = NULL;
	cw = NULL;
	if ((parser = parser_new(argc, argv)) == NULL)
		return (-1);
	if ((ret = init_game(&cw, parser, &champs)) < 0)
	{
		free_params(champs, cw, parser);
		return (ret);
	}
	corewar_set_verbosity(cw, parser->verbose);
	corewar_set_print_aff(cw, parser->disp_aff);
	if (play_corewar(cw, champs, parser) != 0)
	{
		ft_dprintf(2, "An error occured during the game\n");
		free_params(champs, cw, parser);
		return (-1);
	}
	print_winner(cw, parser);
	free_params(champs, cw, parser);
	return (0);
}
