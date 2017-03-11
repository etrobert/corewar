/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:31:31 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 21:34:15 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "corewar.h"

# include <ncurses.h>
# include <errno.h>
# include <fcntl.h>

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

int					play_corewar(t_corewar *corewar);
void				print_corewar(t_corewar *cw, t_visu *visu);
void				print_process_fd(int fd, const t_process *process);
int					print_log(t_visu *visu);
int					play_events(t_visu *visu);

#endif
