/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/14 16:10:58 by tbeldame         ###   ########.fr       */
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

int	add_args_to_lst(char **tmp_args, t_list *args)
{
	int	i;

	i = 0;
	while (tmp_args[i] != NULL)
	{
		if (ft_list_push_back(args, tmp_args[i]) == -1)
		{
			ft_list_apply(args, &free);
			ft_list_delete(args);
			while (tmp_args[i] != NULL)
			{
				free(tmp_args[i]);
				++i;
			}
			return (-1);
		}
		++i;
	}
	return (0);
}

int	get_args(int ac, char **av, t_list **args)
{
	int		i;
	char	**tmp_args;

	i = 1;
	if ((*args = ft_list_new()) == NULL)
		return (-1);
	while (i < ac)
	{
		if ((tmp_args = ft_strsplit_str(av[i], "\t\n\v\f\r ")) == NULL)
			return (-1);
		if (add_args_to_lst(tmp_args, *args) == -1)
		{
			free(tmp_args);
			return (-1);
		}
		free(tmp_args);
		++i;
	}
	return (0);
}

int	process_args(t_list *args, t_list **champs)
{
	t_list_it	it;
	char		*arg;

	it = ft_list_begin(args);
	while (!ft_list_end(args, it))
	{
		arg = (char*)ft_list_it_get(args, it);
		if (arg[0] == '-')
			process_option(&it);
		else
			process_file(&it);
		ft_list_it_inc(&it);
	}
	return (0);
}


int	parse_args(int ac, char **av, t_list **champs)
{
	t_list	*args;

	if (ac < 2)
	{
		ft_dprintf(2, "Not enough arguments, use -h for help");
		return (-1);
	}
	if (get_args(ac, av, &args) == -1)
		return (-1);
	if (process_args(args, champs) == -1)
		return (-1);
	ft_list_apply(args, &free);
	ft_list_delete(args);
	return (0);
}

int main(int argc, char **argv)
{
	t_champion	champ;
	t_list		*list;
	t_list		*champs;
	t_corewar	*cw;
	int			fd;

	//fd = open(argv[1], O_RDONLY);
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
