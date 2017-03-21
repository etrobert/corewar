/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_get_byte_id.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:26:10 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/09 17:08:36 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_id_type			corewar_get_byte_id(t_corewar *corewar, unsigned int pos)
{
	unsigned char	id;

	ft_cbuff_read(corewar->memory_id, &id, pos, sizeof(unsigned char));
	return (id);
}
