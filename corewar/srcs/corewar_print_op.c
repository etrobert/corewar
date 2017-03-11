/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 21:06:57 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 22:32:31 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				corewar_print_op(t_corewar *corewar, t_process *process,
		char *fmt, ...)
{
	va_list			ap;
	int				n;
	char			*str;

	va_start(ap, fmt);
	n = ft_vasprintf(&str, fmt, ap);
	va_end(ap);
	if (n < 0)
		return (n);
	n = corewar_print_log(corewar, "pc %5u | P %5u | %s",
					process_get_pc(process),
					process_get_proc_id(process),
					str);
	free(str);
	return (n);
}
