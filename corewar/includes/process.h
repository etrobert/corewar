/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:50:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/10 17:05:54 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

typedef struct	s_process
{
	char		regs[REG_NUMBER][REG_SIZE];
	char		pc[REG_SIZE];
	bool		carry;
				last_live;
}				t_process;

t_process		*process_new(void);
void			process_init(t_process *proc);
void			process_delete(t_process *proc);

#endif
