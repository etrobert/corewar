/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/14 20:31:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_endian.h"
#include "champion.h"

void	print_bytes(int x)
{
	unsigned int		i;

	i = 0;
	while (i < sizeof(x))
	{
		ft_printf("%#.2x\n", ((unsigned char *)(&x))[i]);
		++i;
	}
}

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

int main(int argc, char **argv)
{
	t_champion	*champ;

	(void)argc;
	(void)argv;

	champ = champion_new();
	if (champion_init(champ, 0, 0) < 0)
	{
		ft_dprintf(2, "ERROR LOADING FILE\n");
		return (-1);
	}
	print_champion(champ);
	champion_delete(champ);
	return (0);
}
