/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:40:53 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 19:14:45 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void			free_params(t_list *champs, t_corewar *cw, t_parser *parser)
{
	parser_delete(parser);
	ft_list_apply(champs, (t_f_apply)&champion_delete);
	ft_list_delete(champs);
	corewar_delete(cw);
}

static bool			int_good_size(void)
{
	return (sizeof(unsigned int) == 4);
}

int 				main_corewar(int argc, char **argv)
{
	t_list		*champs;
	t_corewar	*cw;
	t_parser	*parser;
	t_champion	*winner;

	if (!int_good_size())
	{
		ft_dprintf(2, "This system is not supported.\n");
		return (0);
	}
	champs = NULL;
	parser = NULL;
	cw = NULL;
	if ((parser = parser_new(argc, argv)) == NULL)
		return (-1);
	if (parse_args(parser, &champs) < 0)
	{
		free_params(champs, cw, parser);
		return (-1);
	}
	if (champs == NULL || ft_list_size(champs) < 1)
	{
		ft_dprintf(2, "No champions loaded\n");
		free_params(champs, cw, parser);
		return (-1);
	}
	if (!parser->graphical)
		print_champs(champs);
	if ((cw = corewar_new(champs, 2)) == NULL)
	{
		ft_dprintf(2, "Error creating corewar\n");
		free_params(champs, cw, parser);
		return (-1);
	}
	corewar_set_verbosity(cw, parser->verbose);
	corewar_set_print_aff(cw, parser->disp_aff);
	if (play_corewar(cw, champs, parser) != 0)
	{
		ft_dprintf(2, "An error occured during the game\n");
		free_params(champs, cw, parser);
		return (-1);
	}
	if (corewar_end(cw) && parser->dump_cycle == -1 && !parser->graphical)
	{
		winner = corewar_get_winner(cw);
		ft_printf("Player %u, \"%s\", has won !\n", winner->id,
				winner->header.prog_name);
	}
	free_params(champs, cw, parser);
	return (0);
}
