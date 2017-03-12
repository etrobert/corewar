/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:50:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 21:25:44 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "op.h"
# include "champion.h"

//TODO Choose type
typedef unsigned int	t_reg_type;

typedef struct		s_process
{
	t_reg_type		regs[REG_NUMBER];
	t_reg_type		pc;
	bool			carry;

	t_op			*current_op;
	bool			new_instr;
	t_cycle_type	to_wait;

	t_cycle_type	last_live;
	unsigned int	proc_id;
//	t_id_type		last_living_champ;
}					t_process;

t_process			*process_new(void);
t_process			*process_cpy(const t_process *proc);
void				process_init(t_process *proc);
void				process_delete(t_process *proc);

t_reg_type			process_get_reg(const t_process *proc, unsigned char reg);
void				process_set_reg(t_process *proc, unsigned char reg,
		unsigned int val);
bool				process_valid_reg(unsigned char reg);
t_reg_type			process_get_pc(const t_process *process);
unsigned int		process_get_proc_id(const t_process *process);
void				process_set_proc_id(t_process *process,
		unsigned int proc_id);

void				process_update_pc(t_process *proc, unsigned int value);

#endif
