/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_log.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:03:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:21:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_print_log(const t_corewar *corewar, char *fmt, ...)
{
	va_list			ap;
	int				n;

	va_start(ap, fmt);
	n = corewar_vprint_log(corewar, fmt, ap);
	va_end(ap);
	return (n);
}
