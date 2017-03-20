/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 08:24:20 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/20 20:25:34 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "champion.h"
#include "corewar.h"
#include "args_parser.h"

static int	process_verbose(t_parser *parser)
{
	if (parser->cur_arg == (parser->ac - 1))
		return (-1);
	++parser->cur_arg;
	if (ft_str_test_chars(parser->av[parser->cur_arg], &ft_isdigit))
	{
		if (!ft_strnbrlesseq(parser->av[parser->cur_arg], INT32_STR_MAX) ||
				(parser->verbose = ft_atoi(parser->av[parser->cur_arg])) >
				CW_VB_MAX_ADD)
		{
			ft_dprintf(2, "Invalid verbosity level, use -h for usage\n");
			return (-1);
		}
	}
	else
	{
		parser->verbose = 1;
		--parser->cur_arg;
	}
	return (0);
}

static int	process_champ_num(t_parser *parser, t_list **champs)
{
	int	champ_id;

	if (parser->cur_arg == (parser->ac - 1) ||
			parser->cur_arg == (parser->ac - 2))
		return (-1);
	++parser->cur_arg;
	if (ft_isnumber(parser->av[parser->cur_arg]) &&
		ft_strnbrlesseq(parser->av[parser->cur_arg], INT32_STR_MAX) &&
		!ft_strnbrless(parser->av[parser->cur_arg], INT32_STR_MIN))
	{
		champ_id = ft_atoi(parser->av[parser->cur_arg]);
		++parser->cur_arg;
		if (open_champ_file(parser, champ_id, true, champs) == -1)
			return (-1);
	}
	else
	{
		ft_dprintf(2, "Invalid champion id, use -h for usage\n");
		return (-1);
	}
	return (0);
}

static int	process_dump(t_parser *parser)
{
	if (parser->cur_arg == (parser->ac - 1))
		return (-1);
	++parser->cur_arg;
	if (ft_str_test_chars(parser->av[parser->cur_arg], &ft_isdigit) &&
			ft_strnbrlesseq(parser->av[parser->cur_arg], INT32_STR_MAX))
		parser->dump_cycle = ft_atoi(parser->av[parser->cur_arg]);
	else
	{
		ft_dprintf(2, "Invalid cycle number, use -h for usage\n");
		return (-1);
	}
	return (0);
}

static int	process_file(t_parser *parser)
{
	if (parser->cur_arg == (parser->ac - 1))
		return (-1);
	++parser->cur_arg;
	if ((parser->log_file = 
		open(parser->av[parser->cur_arg], O_RDWR, O_CREAT, O_TRUNC)) < 0)
	{
		ft_dprintf(2, "Failed to open the logfile");
		return (-1);
	}
	return (0);
}

int			parse_options(t_parser *parser, t_list **champs)
{
	if (ft_strcmp("-v", parser->av[parser->cur_arg]) == 0)
		return (process_verbose(parser));
	else if (ft_strcmp("-n", parser->av[parser->cur_arg]) == 0)
		return (process_champ_num(parser, champs));
	else if (ft_strcmp("-dump", parser->av[parser->cur_arg]) == 0)
		return (process_dump(parser));
	else if (ft_strcmp("-g", parser->av[parser->cur_arg]) == 0)
		parser->graphical = true;
	else if (ft_strcmp("-a", parser->av[parser->cur_arg]) == 0)
		parser->disp_aff = true;
	else if (ft_strcmp("-f", parser->av[parser->cur_arg]) == 0)
		return (process_file(parser));
	else if (ft_strcmp("-c", parser->av[parser->cur_arg]) == 0)
		parser->console = true;
	else if (ft_strcmp("-h", parser->av[parser->cur_arg]) == 0)
	{
		print_help();
		return (-1);
	}
	else if (open_champ_file(parser, 0, false, champs) < 0)
			return (-1);
	cleanup_options(parser);
	return (0);
}
