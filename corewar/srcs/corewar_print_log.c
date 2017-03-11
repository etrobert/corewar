/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_log.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:03:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/10 19:53:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_print_log(t_corewar *corewar, char *str)
{
	ft_dprintf(corewar->fd, "[%6u] %s\n", corewar->cycle, str);
}
