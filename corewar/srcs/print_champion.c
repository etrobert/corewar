/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:52 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/18 15:36:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_champion(t_champion *champion)
{
	ft_printf("Here's our hero :\n");
	ft_printf("His name is %s.\n", champion->header.prog_name);
	ft_printf("And here is his story : %s\n", champion->header.comment);
	ft_printf("Lets not forget his weight : %u\n", champion->header.prog_size);
	ft_printf("And that he is before all a magician : %x\n", champion->header.magic);
	ft_printf("And finally the code :\n");
	for (unsigned int i = 0; i < champion->header.prog_size ; ++i)
	{
		ft_printf("%.2#x ", champion->code[i]);
	}
	ft_printf("\n");
}
