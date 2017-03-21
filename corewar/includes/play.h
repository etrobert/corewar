/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:48:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/21 15:03:06 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

# include "corewar.h"
# include "args_parser.h"

# include <ncurses.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/time.h>

# define PRINT_WIDTH	64

typedef struct		s_visu
{
	WINDOW			*board;
	WINDOW			*infos;
	WINDOW			*log;
	int				line;
	int				col;
	bool			pause;
	unsigned int	speed;
	int				log_height;
	int				fds[2];
	int				log_col;
	int				cur_log;
	t_list			*log_lines;
}					t_visu;

int					play_corewar(t_corewar *corewar, t_list *champs,
		t_parser *parser);
int					main_game_visu(t_corewar *corewar, t_visu *visu,
		t_list *champs, t_parser *parser);
int					play_events(t_visu *visu);
int					init_visu_log(t_visu *visu);
void				visu_init(t_visu *visu, t_list *champs);
void				visu_end(t_visu *visu);
void				print_corewar(t_corewar *cw, t_visu *visu, t_list *champs);
void				print_infos(t_corewar *corewar, t_visu *visu,
		t_list *champs);
int					print_log(t_visu *visu);

#endif
