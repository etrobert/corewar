/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_set_proc_id.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 21:04:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 21:17:32 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void				process_set_proc_id(t_process *process,
		unsigned int proc_id)
{
	if (process == NULL)
		return ;
	process->proc_id = proc_id;
}
