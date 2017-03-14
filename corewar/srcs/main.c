/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/14 21:05:25 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"
#include "champion.h"
#include "corewar.h"

#include <fcntl.h>
#include <unistd.h>

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

int	parse_args(int ac, char **av, t_list *champs)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (process_options(ac, av, &i, champs) < 0)
				return (-1);
		}
		else
		{
			if (process_file(av[i], -1, champs) < 0)
				return (-1);
		}
		++i;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_champion	champ;
	t_list		*list;
	t_list		*champs;
	t_corewar	*cw;
	int			fd;

	if (!int_good_size())
	{
		ft_dprintf(2, "This system is not supported.\n");
		return (0);
	}
	parse_args(argc, argv, &champs);

	//if (champion_init(&champ, 1, fd) < 0)
	//{
		//ft_dprintf(2, "ERROR LOADING FILE\n");
		//return (-1);
	//}
	//list = ft_list_new();
	//ft_list_push_back(list, &champ);

	cw = corewar_new(list, 2);

	play_corewar(cw);

	corewar_delete(cw);
	champion_clear(&champ);
	close(fd);
	return (0);
}
