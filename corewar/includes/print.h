/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:33:54 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 19:26:04 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "corewar.h"
# include "args_parser.h"
# include "libft.h"

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

	//Mes trucs sales
	int				log_height;
	int				fds[2];
	int				log_col;
	int				cur_log;
	t_list			*log_lines;
}					t_visu;

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

int					play_corewar(t_corewar *corewar, t_list *champs,
		t_parser *parser);
void				print_corewar(t_corewar *cw, t_visu *visu, t_list *champs);
void				print_infos(t_corewar *corewar, t_visu *visu,
		t_list *champs);
void				print_process_fd(int fd, const t_process *process);
void				print_champion(t_champion *champion);
void				print_args_parser(t_parser *parser);
int					print_log(t_visu *visu);
int					play_events(t_visu *visu);
void				visu_init(t_visu *visu, t_list *champs);
void				visu_end(t_visu *visu);

#endif
