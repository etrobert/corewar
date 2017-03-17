/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vprint_log.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 21:09:48 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/15 18:07:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_vprint_log(t_corewar *corewar, char *fmt,
		va_list ap)
{
	int				n;
	int				n2;

	if ((corewar->verbosity & CW_VB_PRE_CYCLES) == 0)
		n = 0;
	else
	{
		if ((n = ft_dprintf(corewar->fd, "[%6u] ", corewar->cycle)) < 0)
			return (n);
	}
	if ((n2 = ft_vdprintf(corewar->fd, fmt, ap)) < 0)
		return (n2);
	return (n + n2);
}
