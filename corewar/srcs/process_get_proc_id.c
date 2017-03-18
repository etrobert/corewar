/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_get_proc_id.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 21:24:44 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 21:25:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

unsigned int		process_get_proc_id(const t_process *process)
{
	if (process == NULL)
		return (0);
	return (process->proc_id);
}
