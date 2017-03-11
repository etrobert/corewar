/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:16:09 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 19:56:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_fork(t_corewar *corewar, t_process *process)
{
	short			dest;
	int				ret;

	ft_cbuff_read(corewar->memory, &dest, process->pc + 1, sizeof(dest));
	dest = ft_ushort16_big_endian(dest);
	ret = (corewar_fork(corewar, process,
				(process->pc + (dest % IDX_MOD)) % MEM_SIZE));
	corewar_print_log(corewar, "pc %d: fork %hd\n", process->pc, dest);
	corewar_update_process_pc(corewar, process, 3);
	return (ret);
}
