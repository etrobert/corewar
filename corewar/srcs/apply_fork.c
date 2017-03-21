/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:16:09 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/16 19:30:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_fork(t_corewar *corewar, t_process *process)
{
	short			dest;
	int				ret;

	corewar_read(corewar, (t_memory){&dest, sizeof(dest)}, process->pc + 1);
	dest = ft_ushort16_big_endian(dest);
	ret = (corewar_fork(corewar, process,
				(process->pc + (dest % IDX_MOD)) % MEM_SIZE));
	corewar_print_op(corewar, process, "fork %hd\n", dest);
	corewar_update_process_pc(corewar, process, 3);
	return (ret);
}
