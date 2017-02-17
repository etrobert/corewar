/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_by_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:02:06 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 11:18:54 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op				*get_op_by_name(const char *name)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(g_op_tab[i].name, name) == 0)
			return (g_op_tab + i);
		++i;
	}
	return (NULL);
}
