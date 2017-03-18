/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/18 16:34:17 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"
#include "champion.h"
#include "corewar.h"
#include "args_parser.h"

#include <fcntl.h>
#include <unistd.h>

static bool	int_good_size(void)
{
	return (sizeof(unsigned int) == 4);
}

int main(int argc, char **argv)
{
	t_list		*champs;
	t_corewar	*cw;
	t_parser	*parser;

	if (!int_good_size())
	{
		ft_dprintf(2, "This system is not supported.\n");
		return (0);
	}
	champs = NULL;
	if ((parser = parser_new(argc, argv)) == NULL)
		return (-1);
	if (parse_args(parser, &champs) < 0)
	{
		parser_delete(parser);
		return (-1);
	}
	if (champs == NULL || ft_list_size(champs) < 1)
	{
		ft_dprintf(2, "No champions loaded\n");
		parser_delete(parser);
		ft_list_apply(champs, (t_f_apply)&champion_delete);
		ft_list_delete(champs);
		return (-1);
	}

	ft_printf("%d champions loaded\n", ft_list_size(champs));

	if ((cw = corewar_new(champs, 2)) == NULL)
	{
		parser_delete(parser);
		ft_list_apply(champs, (t_f_apply)&champion_delete);
		ft_list_delete(champs);
		ft_dprintf(2, "Error creating corewar\n");
		return (-1);
	}
	corewar_set_verbosity(cw, parser->verbose);

	if (play_corewar(cw, champs, parser) != 0)
	{
		ft_dprintf(2, "An error occured during the game\n");
		parser_delete(parser);
		ft_list_apply(champs, (t_f_apply)&champion_delete);
		ft_list_delete(champs);
	}

	parser_delete(parser);
	ft_list_apply(champs, (t_f_apply)&champion_delete);
	ft_list_delete(champs);
	corewar_delete(cw);
	return (0);
}
