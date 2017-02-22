/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:16:09 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 13:33:34 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					apply_fork(t_corewar *corewar, t_process *process)
{
	short			dest;
	t_process		*cpy;

	ft_cbuff_read(corewar->memory, &dest, process->pc + 1, sizeof(dest));
	dest = ft_ushort16_big_endian(dest);
	if ((cpy = process_cpy(process)) == NULL)
		return (-1);
	cpy->pc = process->pc + (dest % IDX_MOD);
	corewar_add_process(corewar, cpy);
	return (0);
}
