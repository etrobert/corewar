/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:25:56 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 17:27:47 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_lfork(t_corewar *corewar, t_process *process)
{
	short			dest;
	int				ret;

	corewar_read(corewar, (t_memory){&dest, sizeof(dest)}, process->pc + 1);
	dest = ft_ushort16_big_endian(dest);
	ret = (corewar_fork(corewar, process,
				(process->pc + dest) % MEM_SIZE));
	corewar_print_op(corewar, process, "lfork %hd\n", dest);
	corewar_update_process_pc(corewar, process, 3);
	return (ret);
}
