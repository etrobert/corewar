/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:58:36 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 17:44:56 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_winner(t_corewar *corewar, t_parser *parser)
{
	t_champion	*winner;

	if (corewar_end(corewar) && parser->dump_cycle == -1 && !parser->graphical)
	{
		winner = corewar_get_winner(corewar);
		ft_printf("Player %d, \"%s\", has won !\n", winner->id,
				winner->header.prog_name);
	}
}
