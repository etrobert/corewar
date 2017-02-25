/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_corewar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2017/02/24 18:41:05 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

/*static void			print_line(void)
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
}*/

/*void				old_print_corewar(t_corewar *cw)
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
}*/

/*static void			print_infos(t_corewar *corewar, t_visu *visu)
{
	char			*ret;

	(void)visu;
	ft_asprintf(&ret, "cycle : %u", corewar->cycle);
	free(ret);
	ft_asprintf(&ret, "process : %d", ft_list_size(corewar->process));
	free(ret);
	ft_asprintf(&ret, "cycle_to_die : %u", corewar->cycles_to_die);
	free(ret);
}*/

static void			print_byte(t_corewar *corewar, unsigned int pos,
		t_visu *visu)
{
	unsigned char	byte;
	char			*ret;

	byte = corewar_get_byte(corewar, pos);
	ft_asprintf(&ret, "%.2x ", byte);
	visu->text = TTF_RenderText_Blended(visu->font, ret, visu->white);
	free(ret);
}

void				print_corewar(t_corewar *cw, t_visu *visu)
{
	unsigned int	i;
	unsigned int	j;

	visu->pos.x = 0;
	visu->pos.y = 0;
	j = 0;
	while (j * PRINT_WIDTH < MEM_SIZE)
	{
		i = 0;
		visu->pos.x = 0;
		while (i < PRINT_WIDTH && j * PRINT_WIDTH + i < MEM_SIZE)
		{
			print_byte(cw, j * PRINT_WIDTH + i, visu);
			SDL_BlitSurface(visu->text, NULL, visu->screen, &(visu->pos));
//			SDL_Flip(visu->screen);
			visu->pos.x += 20;
			i++;
		}
		visu->pos.y += 15;
		j++;
	}
}
