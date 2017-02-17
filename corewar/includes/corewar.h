/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:03:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:31:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "champion.h"
# include "process.h"

//Push_front lorsquon ajoute un process

typedef struct		s_corewar
{
	unsigned char	memory[MEM_SIZE];
	t_list			*process;
	t_cycle_type	cycle;
}					t_corewar;

t_corewar			*corewar_new(t_list *champions);
int					corewar_init(t_corewar *corewar, t_list *champions);
void				corewar_delete(t_corewar *corewar);

// Plays the whole game and returns the winner's id
t_id_type			corewar_play(t_corewar *corewar);

void				corewar_advance(t_corewar *corewar);

/*
** Internal
*/

void				corewar_update_process(t_corewar *corewar,
		t_process *process);
int					corewar_fork(t_corewar *corewar,
		t_process *parent, t_reg_type pc);
void				apply_nothing(t_corewar *corewar, t_process *process);
void				apply_live(t_corewar *corewar, t_process *process);

#endif
