/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:06:24 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/15 16:39:01 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PARSER_H
# define ARGS_PARSER

# include "libft.h"

# include <stdbool.h>
# include <unistd.h>

typedef strct	s_parser
{
	t_bool		graphical;
	int			verbose;
	int			dump_cycle;
	int			latest_id;
	int			cur_arg;
	int			ac;
	char		**av;
}				t_parser;

#endif
