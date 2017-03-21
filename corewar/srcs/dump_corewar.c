/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:24:38 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 15:24:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	print_byte(const t_corewar *corewar, unsigned int pos)
{
	unsigned char	byte;

	byte = corewar_get_byte(corewar, pos);
	ft_printf(" %.2x", byte);
}

void		dump_corewar(const t_corewar *corewar)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j * DUMP_WIDTH < MEM_SIZE)
	{
		i = 0;
		ft_printf("0x%.8x :", j * DUMP_WIDTH);
		while (i < DUMP_WIDTH && j * DUMP_WIDTH + i < MEM_SIZE)
		{
			print_byte(corewar, j * DUMP_WIDTH + i);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}
