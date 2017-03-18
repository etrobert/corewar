/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:35:32 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/15 19:44:51 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"

t_parser	*parser_new(int ac, char **av)
{
	t_parser	*parser;

	if (ac < 2)
	{
		print_help();
		return (NULL);
	}
	if ((parser = (t_parser*)malloc(sizeof(t_parser))) == NULL)
		return (NULL);
	parser->graphical = false;
	parser->verbose = -1;
	parser->dump_cycle = -1;
	parser->latest_id = 0;
	parser->cur_arg = 1;
	parser->ac = ac;
	parser->av = av;
	return (parser);
}
