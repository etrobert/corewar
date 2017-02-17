/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:32:53 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:41:56 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

t_process			*process_cpy(t_process *proc)
{
	t_process		*cpy;

	if ((cpy = (t_process *)(ft_memdup(proc, sizeof(t_process)))) == NULL)
		return (NULL);
	//Carry stays the same ?
	return (cpy);
}
