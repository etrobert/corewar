/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:53:33 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/15 20:45:37 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

t_process			*process_new(t_reg_type r1, t_reg_type pc)
{
	t_process		*process;

	if ((process = (t_process *)(malloc(sizeof(t_process)))) == NULL)
		return (NULL);
	process_init(process, r1, pc);
	return (process);
}
