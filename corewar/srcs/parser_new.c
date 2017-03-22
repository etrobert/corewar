/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:35:32 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 15:07:09 by mverdier         ###   ########.fr       */
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
	parser->disp_aff = false;
	parser->console = false;
	parser->v_set = false;
	parser->log_file = NULL;
	parser->av = av;
	parser->ac = ac;
	parser->verbose = 0;
	parser->dump_cycle = -1;
	parser->latest_id = 0;
	parser->cur_arg = 1;
	return (parser);
}
