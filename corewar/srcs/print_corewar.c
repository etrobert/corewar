/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_corewar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:26:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/15 23:16:54 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	print_line(void)
{
	int		i;

	i = 0;
	while (i < PRINT_WIDTH)
	{
		ft_printf("-- ");
		++i;
	}
	ft_putchar('\n');
}

void		print_corewar(t_corewar *cw)
{
	int		i;
	int		j;

	print_line();
	j = 0;
	while (j * PRINT_WIDTH < MEM_SIZE)
	{
		i = 0;
		while (i < PRINT_WIDTH && j * PRINT_WIDTH + i < MEM_SIZE)
		{
			ft_printf("%.2x ", cw->memory[j * PRINT_WIDTH + i]);
			++i;
		}
		ft_printf("\n");
		++j;
	}
	print_line();
}