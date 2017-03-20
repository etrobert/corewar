/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:41:47 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/20 20:42:37 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_help(void)
{
	ft_printf("Usage :\n\t./corewar [-v N] [-dump N] [-g] [-a] [-h] [-c]");
	ft_printf("[-f <filename>] [[-n N] <champion>.cor] ...\n\n");
	ft_printf("Champions :\n\tCan be sent with or without a defined number ");
	ft_printf("(defined by the program if\n\tnot sent)\n");
	ft_printf("\t-n N\t: Specifies the following .cor champion number\n\n");
	ft_printf("Options :\n\t-v N\t\t: Sets the verbosity level ");
	ft_printf("(0 to CW_VB_MAX) can be added together\n");
	ft_printf("\t\t- 0 : Displays only the winner\n");
	ft_printf("\t\t- 1 : Display champions lives\n");
	ft_printf("\t\t- 2 : Display cycles and CYCLES_TO_DIE\n");
	ft_printf("\t\t- 4 : Displays operations\n");
	ft_printf("\t\t- 8 : Displays deaths\n");
	ft_printf("\t\t- 16 : Displays every process movement\n");
	ft_printf("\t\t- 32 : Adds a cycle prefix for every info\n");
	ft_printf("\t\t- 64 : Displays the where the PC is for an operation\n");
	ft_printf("\t-dump N\t\t: Dumps the content of the memory after N cycles\n");
	ft_printf("\t-f <file>\t: Enables logging to a file\n");
	ft_printf("\t-g\t\t: Enables the graphical mode (ncurses)\n");
	ft_printf("\t-a\t\t: Enables printing of aff instrucions\n");
	ft_printf("\t-c\t\t: Enables the console in graphical mode\n");
	ft_printf("\t-h\t\t: Displays this help message\n");
	return ;
}
