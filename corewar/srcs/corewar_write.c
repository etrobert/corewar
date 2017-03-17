/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:13:49 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/14 21:32:49 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_write(t_corewar *corewar, t_memory mem, size_t pos,
		t_id_type id)
{
	ft_cbuff_write(corewar->memory, mem.ptr, pos, mem.size);
	ft_cbuff_set(corewar->memory_id, (unsigned char)id, pos, mem.size);
}
