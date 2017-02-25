/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_get_byte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:43:22 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/25 15:02:32 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char		corewar_get_byte(const t_corewar *corewar, unsigned int pos)
{
	unsigned char	byte;

	ft_cbuff_read(corewar->memory, &byte, pos, sizeof(unsigned char));
	return (byte);
}
