/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:33:54 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/10 15:34:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "corewar.h"

# include <ncurses.h>

# define PRINT_WIDTH	64

typedef struct		s_visu
{
	WINDOW			*board;
	WINDOW			*infos;
	int				line;
	int				col;
	bool			pause;
	unsigned int	speed;
}					t_visu;

int					play_corewar(t_corewar *corewar);
void				print_corewar(t_corewar *cw, t_visu *visu);
void				print_process_fd(int fd, const t_process *process);
int					play_events(t_visu *visu);

#endif
