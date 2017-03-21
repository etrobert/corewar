/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 15:07:11 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"
#include "champion.h"
#include "corewar.h"
#include "args_parser.h"

#include <fcntl.h>
#include <unistd.h>

int			main(int argc, char **argv)
{
	return (main_corewar(argc, argv));
	return (0);
}
