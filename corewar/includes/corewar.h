/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:03:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/15 20:37:41 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "champion.h"
# include "process.h"

typedef struct		s_corewar
{
	unsigned char	memory[MEM_SIZE];
	t_list			*process;
}					t_corewar;

t_corewar			*corewar_new(t_list *champions);
int					corewar_init(t_corewar *corewar, t_list *champions);
void				corewar_delete(t_corewar *corewar);

// Plays the whole game and returns the winner's id
t_id_type			corewar_play(t_corewar *corewar);

void				corewar_advance(t_corewar *corewar);

#endif
