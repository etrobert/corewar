/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <tbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:18:37 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 15:29:54 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"

void	cleanup_options(t_parser *parser)
{
	if (parser->graphical && parser->verbose > 0 && parser->log_file != NULL)
		parser->console = true;
	else if (parser->log_file != NULL && !parser->v_set)
	{
		parser->v_set = true;
		parser->verbose = VB_DEFAULT;
	}
	else if (parser->console && parser->graphical && !parser->v_set)
	{
		parser->v_set = true;
		parser->verbose = VB_DEFAULT;
	}
	else if (parser->console && !parser->graphical)
		parser->graphical = true;
	return ;
}
