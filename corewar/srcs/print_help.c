/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:41:47 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/21 20:21:13 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_help(void)
{
	ft_printf("Usage :\n\t./corewar [-v N] [-dump N] [-g] [-a] [-h] [-c]"
	"[-f <filename>] [[-n N] <champion>.cor] ...\n\n"
	"Champions :\n\tCan be sent with or without a defined number "
	"(defined by the program if\n\tnot sent)\n"
	"\t-n N\t: Specifies the following .cor champion number\n\n"
	"Options :\n\t-v N\t\t: Sets the verbosity level "
	"(0 to CW_VB_MAX) can be added together\n"
	"\t\t- 0 : Displays only the winner\n"
	"\t\t- 1 : Display champions lives\n"
	"\t\t- 2 : Display cycles and CYCLES_TO_DIE\n"
	"\t\t- 4 : Displays operations\n"
	"\t\t- 8 : Displays deaths\n"
	"\t\t- 16 : Displays every process movement\n"
	"\t\t- 32 : Adds a cycle prefix for every info\n"
	"\t\t- 64 : Displays the where the PC is for an operation\n"
	"\t-dump N\t\t: Dumps the content of the memory after N cycles\n"
	"\t-f <file>\t: Enables logging to a file\n"
	"\t-g\t\t: Enables the graphical mode (ncurses)\n"
	"\t-a\t\t: Enables printing of aff instrucions\n"
	"\t-c\t\t: Enables the console in graphical mode\n"
	"\t-h\t\t: Displays this help message\n");
	return ;
}
