/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:50:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 16:13:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "op.h"

//TODO Choose type
typedef unsigned int	t_reg_type;

typedef struct		s_process
{
	t_reg_type		regs[REG_NUMBER];
	t_reg_type		pc;
	bool			carry;
	t_op			*current_op;
	t_cycle_type	to_wait;
}					t_process;

t_process			*process_new(void);
t_process			*process_cpy(t_process *proc);
void				process_init(t_process *proc);
void				process_delete(t_process *proc);
void				process_update_pc(t_process *proc, unsigned int value);

#endif
