/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:03:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 23:26:16 by etrobert         ###   ########.fr       */
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
	t_cycle_type	last_check;
	t_cycle_type	cycles_to_die;
	t_cycle_type	clear_checks;
	unsigned int	nbr_live;
}					t_corewar;

typedef int			(*t_f_cw_op)(t_corewar *, t_process *);

t_corewar			*corewar_new(t_list *champions);
int					corewar_init(t_corewar *corewar, t_list *champions);
void				corewar_delete(t_corewar *corewar);

int					corewar_advance(t_corewar *corewar);
bool				corewar_end(t_corewar *corewar);

/*
** Internal
*/

void				corewar_update_process_pc(t_corewar *corewar,
		t_process *proc, int value);

void				corewar_check(t_corewar *corewar);
/*
** Reads the op pointed to by process->pc, saves it and
** sets process wait time accordingly
*/
void				corewar_update_process(t_corewar *corewar,
		t_process *process);

int					corewar_add_process(t_corewar *corewar, t_process *process);
int					corewar_fork(t_corewar *corewar,
		t_process *parent, t_reg_type pc);
void				corewar_kill_process(t_corewar *corewar);

/*
** op functions
*/

int					apply_nothing(t_corewar *corewar, t_process *process);
int					apply_live(t_corewar *corewar, t_process *process);
int					apply_fork(t_corewar *corewar, t_process *process);
int					apply_zjmp(t_corewar *corewar, t_process *process);

#endif
