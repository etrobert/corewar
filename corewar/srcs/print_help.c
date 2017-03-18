/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:41:47 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/17 11:21:24 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_help(void)
{
	ft_printf("Usage :\n\t./corewar [-v N] [-dump N] [-g] [-a] [-h] ");
	ft_printf("[[-n N] champion1.cor] ...\n\n");
	ft_printf("Champions :\n\tCan be sent with or without a defined number ");
	ft_printf("(defined by the program if\n\tnot sent)\n");
	ft_printf("\t-n N\t: Specifies the following .cor champion number\n\n");
	ft_printf("Options :\n\t-v N\t: Sets the verbosity level ");
	ft_printf("(0 to CW_VB_MAX) can be added together\n");
	ft_printf("\t\t\t- Need\n");
	ft_printf("\t\t\t- details\n");
	ft_printf("\t\t\t- for\n");
	ft_printf("\t\t\t- the\n");
	ft_printf("\t\t\t- various\n");
	ft_printf("\t\t\t- levels\n");
	ft_printf("\t-dump N\t: Dumps the content of the memory after N cycles\n");
	ft_printf("\t-g\t: Enables the graphical mode (ncurses)\n");
	ft_printf("\t-a\t: Enables printing of aff instrucions\n");
	ft_printf("\t-h\t: Displays this help message\n");
	return ;
}
