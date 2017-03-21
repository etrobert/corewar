/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:05:43 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/09 16:46:12 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void				print_process_fd(int fd, const t_process *process)
{
	ft_dprintf(fd, "pc : %d; ", process->pc);
	ft_dprintf(fd, "carry : %d; ", process->carry);
	ft_dprintf(fd, "new_instr : %d; ", process->new_instr);
	ft_dprintf(fd, "to_wait : %d; ", process->to_wait);
	ft_dprintf(fd, "current op : %s\n", process->current_op->name);
}
