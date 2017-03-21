/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:58:36 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/16 20:36:49 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_read(const t_corewar *corewar,
		t_memory mem, size_t pos)
{
	ft_cbuff_read(corewar->memory, mem.ptr, pos, mem.size);
}
