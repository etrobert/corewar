/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:59:47 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 21:02:05 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//debug
#include "print.h"

int					corewar_play(t_corewar *corewar)
{
	int				ret;

	if (corewar == NULL)
		return (0);
	while (!corewar_end(corewar))
	{
		ft_printf("\033[2J");
		ft_printf("cycle : %u ; ", corewar->cycle);
		ft_printf("process : %d ;", ft_list_size(corewar->process));
		ft_printf("cycle_to_die : %u\n", corewar->cycles_to_die);
		print_corewar(corewar);
		if ((ret = corewar_advance(corewar)) < 0)
			return (ret);
		usleep(100000);
	}
	return (0);
}
