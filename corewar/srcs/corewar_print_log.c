/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_log.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:03:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 21:16:18 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_log(t_corewar *corewar, char *fmt, ...)
{
	va_list			ap;
	int				n;

	va_start(ap, fmt);
	n = corewar_vprint_log(corewar, fmt, ap);
	va_end(ap);
	return (n);
}
