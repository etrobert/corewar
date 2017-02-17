/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:50:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/15 20:09:56 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "op.h"

//TODO Choose type
typedef unsigned int	t_reg_type;
//TODO Choose type
typedef unsigned int	t_cycle_type;

typedef struct		s_process
{
	t_reg_type		regs[REG_NUMBER];
	t_reg_type		pc;
	bool			carry;
	t_cycle_type	last_live;
}					t_process;

t_process			*process_new(t_reg_type r1, t_reg_type pc);
t_process			*process_cpy(t_process *proc);
void				process_init(t_process *proc, t_reg_type r1, t_reg_type pc);
void				process_delete(t_process *proc);

#endif
