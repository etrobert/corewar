/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:30:29 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:30:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void				print_champion(t_champion *champion)
{
	unsigned int	i;

	ft_printf("Here's our hero :\n");
	ft_printf("His name is %s.\n", champion->header.prog_name);
	ft_printf("And here is his story : %s\n", champion->header.comment);
	ft_printf("Lets not forget his weight : %u\n", champion->header.prog_size);
	ft_printf("And that he is before all a magician : %x\n",
			champion->header.magic);
	ft_printf("And finally the code :\n");
	i = 0;
	while (i < champion->header.prog_size)
	{
		ft_printf("%.2#x ", champion->code[i]);
		++i;
	}
	ft_printf("\n");
}
