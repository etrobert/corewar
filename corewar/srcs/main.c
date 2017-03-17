/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/16 17:43:11 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"
#include "champion.h"
#include "corewar.h"
#include "args_parser.h"

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

int	parse_args(t_parser *parser,  t_list **champs)
{
	while (parser->cur_arg < parser->ac)
	{
		if (parser->av[parser->cur_arg][0] == '-')
		{
			if (process_options(parser, champs) < 0)
				return (-1);
		}
		else
		{
			if (open_champ_file(parser, -1, champs) < 0)
				return (-1);
		}
		++parser->cur_arg;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_list		*champs;
	t_corewar	*cw;
	t_parser	*parser;

	if (!int_good_size())
	{
		ft_dprintf(2, "This system is not supported.\n");
		return (0);
	}
	champs = NULL;
	if ((parser = parser_new(argc, argv)) == NULL)
		return (-1);
	if (parse_args(parser, &champs) < 0)
		return (-1);
	if (champs == NULL || ft_list_size(champs) < 1)
	{
		ft_dprintf(2, "No champions loaded\n");
		return (-1);
	}

	ft_printf("%d champions loaded\n", ft_list_size(champs));

	cw = corewar_new(champs, 2);
	//corewar_set_verbosity(cw, parser->verbose);
	//does not exist yet

	play_corewar(cw, champs);

	corewar_delete(cw);
	return (0);
}
