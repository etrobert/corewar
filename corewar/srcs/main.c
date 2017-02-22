/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/22 23:30:34 by etrobert         ###   ########.fr       */
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

int	play_corewar(t_corewar *corewar)
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
	if ((champ = champion_new()) == NULL)
	{
		ft_dprintf(2, "ERROR CREATING CHAMPION\n");
		return (-1);
	}
	if (champion_init(champ, 0, 0) < 0)
	{
		ft_dprintf(2, "ERROR LOADING FILE\n");
		champion_delete(champ);
		return (-1);
	}
	list = ft_list_new();
	ft_list_push_back(list, champ);
	cw = corewar_new(list);

	play_corewar(cw);

	corewar_delete(cw);
	champion_delete(champ);
	return (0);
}
