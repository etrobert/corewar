/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:50:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/14 20:58:22 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

//TODO Choose type
typedef unsigned long	t_reg_type;

typedef struct	s_process
{
	t_reg_type	regs[REG_NUMBER];
	t_reg_type	pc;
	bool		carry;
				last_live;
}				t_process;

t_process		*process_new(void);
t_process		*process_cpy(t_process *proc);
void			process_init(t_process *proc);
void			process_delete(t_process *proc);

#endif
