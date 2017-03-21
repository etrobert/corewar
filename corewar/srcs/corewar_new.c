/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 21:00:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 20:58:11 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar			*corewar_new(t_list *champions, int fd)
{
	t_corewar		*cw;

	if ((cw = (t_corewar *)(malloc(sizeof(t_corewar)))) == NULL)
		return (NULL);
	if (corewar_init(cw, champions, fd) < 0)
	{
		corewar_delete(cw);
		return (NULL);
	}
	return (cw);
}
