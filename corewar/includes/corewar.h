/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:03:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/18 23:57:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "champion.h"
# include "process.h"

typedef struct		s_corewar
{
	t_cbuff			*memory;
	t_list			*process;
	t_cycle_type	cycle;
}					t_corewar;

t_corewar			*corewar_new(t_list *champions);
int					corewar_init(t_corewar *corewar, t_list *champions);
void				corewar_delete(t_corewar *corewar);

t_id_type			corewar_play(t_corewar *corewar);

void				corewar_advance(t_corewar *corewar);

/*
** Internal
*/

void				corewar_update_process_pc(t_corewar *corewar,
		t_process *proc, int value);
void				corewar_update_process(t_corewar *corewar,
		t_process *process);
int					corewar_fork(t_corewar *corewar,
		t_process *parent, t_reg_type pc);
void				apply_nothing(t_corewar *corewar, t_process *process);
void				apply_live(t_corewar *corewar, t_process *process);
void				apply_zjmp(t_corewar *corewar, t_process *process);

#endif
