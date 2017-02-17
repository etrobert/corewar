/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 18:50:51 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "champion.h"
#include "corewar.h"
#include "print.h"

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

static bool	int_good_size(void)
{
	return (sizeof(unsigned int) == 4);
}

int main(int argc, char **argv)
{
	t_champion	*champ;
	t_list		*list;
	t_corewar	*cw;

	(void)argc;
	(void)argv;

	if (!int_good_size())
	{
		ft_dprintf(2, "This system is not supported.\n");
		return (0);
	}
	champ = champion_new();
	if (champion_init(champ, 0, 0) < 0)
	{
		ft_dprintf(2, "ERROR LOADING FILE\n");
		champion_delete(champ);
		return (-1);
	}
	//print_champion(champ);
	list = ft_list_new();
	ft_list_push_back(list, champ);
	ft_list_push_back(list, champ);
	cw = corewar_new(list);


		print_corewar(cw);
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		corewar_advance(cw);
		++i;
	}

	//corewar_delete(cw);
	champion_delete(champ);
	return (0);
}
