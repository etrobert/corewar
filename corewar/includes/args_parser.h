/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:06:24 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/15 18:29:48 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PARSER_H
# define ARGS_PARSER_H

# include "libft.h"

# include <stdbool.h>
# include <unistd.h>

typedef struct	s_parser
{
	bool		graphical;
	int			verbose;
	int			dump_cycle;
	int			latest_id;
	int			cur_arg;
	int			ac;
	char		**av;
}				t_parser;

t_parser		*parser_new(int ac, char **av);
int				open_champ_file(t_parser *parser, int champ_id, t_list *champs);
int				process_options(t_parser *parser, t_list *champs);

#endif
