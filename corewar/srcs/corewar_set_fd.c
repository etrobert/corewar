/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_set_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:27:31 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/07 17:28:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_set_fd(t_corewar *corewar, int fd)
{
	if (corewar == NULL)
		return ;
	corewar->fd = fd;
}
