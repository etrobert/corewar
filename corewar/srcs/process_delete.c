/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:45:15 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 12:45:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void				process_delete(t_process *proc)
{
	free(proc);
}
