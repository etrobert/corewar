/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 21:06:57 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 11:22:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				corewar_print_op(const t_corewar *corewar,
		const t_process *process, char *fmt, ...)
{
	va_list			ap;
	int				n;
	char			*str;

	if ((corewar->verbosity & CW_VB_OP) == 0)
		return (0);
	va_start(ap, fmt);
	n = ft_vasprintf(&str, fmt, ap);
	va_end(ap);
	if (n < 0)
		return (n);
	if ((corewar->verbosity & CW_VB_OP_PC) == 0)
		n = corewar_print_log(corewar, "P %5u | %s",
				process_get_proc_id(process), str);
	else
		n = corewar_print_log(corewar, "pc %5u | P %5u | %s",
				process_get_pc(process),
				process_get_proc_id(process),
				str);
	free(str);
	return (n);
}
