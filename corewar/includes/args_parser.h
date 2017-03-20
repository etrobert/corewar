/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:06:24 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/20 20:11:12 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PARSER_H
# define ARGS_PARSER_H

# include "libft.h"
# include "corewar.h"

# include <stdbool.h>
# include <unistd.h>

# define INT32_STR_MAX "2147483647"
# define INT32_STR_MIN "-2147483648"

# define VB_DEFAULT (CW_VB_LIVE | CW_VB_DEATHS | CW_VB_PRE_CYCLES | CW_VB_OP_PC)

typedef struct	s_parser
{
	bool		graphical;
	bool		disp_aff;
	bool		console;
	char		**av;
	int			ac;
	int			log_file;
	int			verbose;
	int			dump_cycle;
	int			latest_id;
	int			cur_arg;
}				t_parser;

t_parser		*parser_new(int ac, char **av);
void			parser_delete(t_parser *parser);
int				parse_args(t_parser *parser, t_list **champs);
int				open_champ_file(t_parser *parser, int champ_id, bool set_id, t_list **champs);
int				parse_options(t_parser *parser, t_list **champs);
void			print_help(void);
bool			ft_strnbrless(char *nbr1, char *nbr2);
bool			ft_strnbrlesseq(char *nbr1, char *nbr2);
void			cleanup_options(t_parser *parser);

#endif
