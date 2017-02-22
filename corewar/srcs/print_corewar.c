/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_corewar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:26:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 13:52:08 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void			print_line(void)
{
	int				i;

	i = 0;
	while (i < PRINT_WIDTH)
	{
		ft_printf("-- ");
		++i;
	}
	ft_putchar('\n');
}

static void			print_color(t_corewar *corewar, unsigned int pos)
{
	t_list_it		it;
	t_process		*process;

	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		process = (t_process *)ft_list_it_get(corewar->process, it);
		if (process->pc == pos)
		{
			ft_printf("\033[31m");
			return ;
		}
		ft_list_it_inc(&it);
	}
}

static void			reset_color(void)
{
	ft_printf("\033[0m");
}

static void			print_byte(t_corewar *corewar, unsigned int pos)
{
	unsigned char	byte;

	print_color(corewar, pos);
	ft_cbuff_read(corewar->memory, &byte, pos, sizeof(unsigned char));
	ft_printf("%.2x ", byte);
	reset_color();
}

void				print_corewar(t_corewar *cw)
{
	unsigned int	i;
	unsigned int	j;

	print_line();
	j = 0;
	while (j * PRINT_WIDTH < MEM_SIZE)
	{
		i = 0;
		while (i < PRINT_WIDTH && j * PRINT_WIDTH + i < MEM_SIZE)
		{
			print_byte(cw, j * PRINT_WIDTH + i);
			++i;
		}
		ft_printf("\n");
		++j;
	}
	print_line();
}
