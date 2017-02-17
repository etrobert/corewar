/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:53:33 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:34:36 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

t_process			*process_new(void)
{
	t_process		*process;

	if ((process = (t_process *)(malloc(sizeof(t_process)))) == NULL)
		return (NULL);
	process_init(process);
	return (process);
}
