/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <tbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:18:37 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/20 20:29:24 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"

void	cleanup_options(t_parser *parser)
{
	if (parser->graphical == true && parser->verbose > 0
		&& parser->log_file > 0)
		parser->console = true;
	else if (parser->log_file > 0 && parser->verbose > 0)
		parser->verbose = VB_DEFAULT;
	else if (parser->console == true && parser->graphical == true
				&& parser->verbose > 0)
		parser->verbose = VB_DEFAULT;
	return ;
}
