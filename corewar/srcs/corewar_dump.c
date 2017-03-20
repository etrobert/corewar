/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:46:18 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/20 18:11:01 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_byte(const t_corewar *corewar, unsigned int pos)
{
	unsigned char	byte;

	byte = corewar_get_byte(corewar, pos);
	ft_printf(" %.2x", byte);
}

void		corewar_dump(const t_corewar *corewar)
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
