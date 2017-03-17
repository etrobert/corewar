/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 19:17:18 by mverdier         ###   ########.fr       */
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



char	*********************print_args_parser_struct_result_to_know_if_it_works_fine_cause_it_would_suck_if_it_does_not(t_parser *parser)
{
	ft_printf("Heyyyy\n");
	ft_printf("Graphical : %d\n", parser->graphical);
	ft_printf("Display Aff : %d\n", parser->disp_aff);
	ft_printf("Verbosity Level : %d\n", parser->verbose);
	ft_printf("Dump Cycle : %d\n", parser->dump_cycle);
	ft_printf("Latest Contestant id : %d\n", parser->latest_id);
	ft_printf("And that's everything that you should needd\n");
	return (NULL);
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
	print_args_parser_struct_result_to_know_if_it_works_fine_cause_it_would_suck_if_it_does_not(parser);

	cw = corewar_new(champs, 2);
	corewar_set_verbosity(cw, parser->verbose);
	//does not exist yet

	play_corewar(cw, champs, parser);

	corewar_delete(cw);
	return (0);
}
