/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:46:11 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/15 18:52:19 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "champion.h"
#include "corewar.h"
#include "args_parser.h"

static int	process_verbose(t_parser *parser)
{
	if (parser->cur_arg == (parser->ac - 1))
		return (-1);
	++parser->cur_arg;
	//because verbose level is 1 to 4 comparing the char directly could be better
	//lol nope
	if (ft_str_test_chars(parser->av[parser->cur_arg], &ft_isdigit))
	{
		//set verbose level
		//check the overflow crap
		if ((parser->verbose = ft_atoi(parser->av[parser->cur_arg])) > 31)
		{
			ft_dprintf(2, "Invalid verbosity level, use -h for usage\n");
			return (-1);
		}
	}
	else
		return (-1);
	return (0);
}

static int	process_champ_num(t_parser *parser, t_list *champs)
{
	int	champ_id;

	if (parser->cur_arg == (parser->ac - 1) ||
			parser->cur_arg == (parser->ac - 2))
		return (-1);
	++parser->cur_arg;
	if (ft_str_test_chars(parser->av[parser->cur_arg], &ft_isdigit))
	{
		if ((champ_id = ft_atoi(parser->av[parser->cur_arg])) < 0)
		{
			ft_dprintf(2, "Invalid champion id\n");
			return (-1);
		}
		++parser->cur_arg;
		if (open_champ_file(parser, champ_id, champs) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

static int	process_dump(t_parser *parser)
{
	if (parser->cur_arg == (parser->ac - 1))
		return (-1);
	++(parser->cur_arg);
	if (ft_str_test_chars(parser->av[parser->cur_arg], &ft_isdigit))
	{
		//check overflow
		if ((parser->dump_cycle = ft_atoi(parser->av[parser->cur_arg])) < 0)
		{
			ft_dprintf(2, "Invalid cycle number\n");
			return (-1);
		}
	}
	else
		return (-1);
	return (0);
}

int			process_options(t_parser *parser, t_list *champs)
{
	if (ft_strcmp("-v", parser->av[parser->cur_arg]) == 0)
		return (process_verbose(parser));
	else if (ft_strcmp("-n", parser->av[parser->cur_arg]) == 0)
		return (process_champ_num(parser, champs));
	else if (ft_strcmp("-dump", parser->av[parser->cur_arg]) == 0)
		return (process_dump(parser));
	else if (ft_strcmp("-g", parser->av[parser->cur_arg]) == 0)
		parser->graphical = true;
	else if (ft_strcmp("-h", parser->av[parser->cur_arg]) == 0)
	{
		//print_help();
		//not implemented yet
		return (-1);
	}
	else
	{
		if (open_champ_file(parser, -1, champs) < 0)
			return (-1);
	}
	return (0);
}
