/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:44:38 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/18 15:45:08 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void				print_args_parser(t_parser *parser)
{
	ft_printf("Heyyyy\n");
	ft_printf("Graphical : %d\n", parser->graphical);
	ft_printf("Display Aff : %d\n", parser->disp_aff);
	ft_printf("Verbosity Level : %d\n", parser->verbose);
	ft_printf("Dump Cycle : %d\n", parser->dump_cycle);
	ft_printf("Latest Contestant id : %d\n", parser->latest_id);
	ft_printf("And that's everything that you should needd\n");
}
