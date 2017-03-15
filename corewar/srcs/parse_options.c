r* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:46:11 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/15 16:35:00 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "champion.h"
#include "corewar.h"

static int	process_verbose(int ac, char **av, int *i)
{
	char	*tmp;

	if (i == (ac - 1))
		return (-1);
	++(*i);
	//because verbose level is 1 to 4 comparing the char directly could be better
	if (ft_str_test_chars(av[(*i)], &ft_isdigit))
	{
		//check if verbose is already set?
		//set verbose level
		ft_atoi(av[(*i)]);/get the verbose level
	}
	else
		return (-1);
	return (0);
}

static int	process_champ_num(int ac, char **av, int *i, t_list *champs)
{
	if (i == (ac - 1) || i == (ac - 2))
		return (-1);
	(*i)++;
	if (ft_str_test_chars(av[(*i)], &ft_isdigit))
	{
		champ_id = ft_atoi(av[(*i)]);
		(*i)++;
		if (process_file(av[(*i)], champ_id, champs) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

static int	process_dump(int ac, char **av, int *i)
{
	if (i == (ac - 1))
		return (-1);
	(*i)++;
	if (ft_str_test_chars(av[(*i)], &ft_isdigit))
	{
		//check if dump cycle is already set?
		//set dump cycle
		dump_cycle = ft_atoi(av[(*i)]);
	}
	else
		return (-1);
	return (0);
}

int			process_options(int ac, char **av, int *i, t_list *champs)
{
	if (ft_strcmp("-v", av[i]) == 0)
		return (process_verbose(ac, av, i));
	else if (ft_strcmp("-n", av[i]) == 0)
		return (process_champ_num(ac, av, i, champs));
	else if (ft_strcmp("-dump", av[i]) == 0)
		return (process_dump(ac, av, i));
	else if (ft_strcmp("-g", av[i]) == 0)
	{
		//enable graphical mode
	}
	else if (ft_strcmp("-h", av[i]) == 0)
	{
		print_help();
		return (-1);
	}
	else
	{
		if (process_file(ac, av[i], -1, champs) < 0)
			return (-1);
	}
	return (0);
}
