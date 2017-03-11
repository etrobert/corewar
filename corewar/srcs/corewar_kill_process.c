/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_kill_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:16:52 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 20:46:38 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_kill_process(t_corewar *corewar)
{
	t_list_it		it;
	t_process		*process;

	it = ft_list_begin(corewar->process);
	while (!ft_list_it_end(corewar->process, it))
	{
		process = (t_process *)(ft_list_it_get(corewar->process, it));
		if (process->last_live <= corewar->last_check)
		{
			corewar_print_log(corewar, "A process on pc:[%d] died\n",
					process->pc);
			process_delete(process);
			ft_list_erase(corewar->process, it);
		}
		ft_list_it_inc(&it);
	}
}
