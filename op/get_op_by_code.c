/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_by_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:57:43 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 11:05:05 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op				*get_op_by_code(unsigned char op_code)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (g_op_tab[i].op_code == op_code)
			return (g_op_tab + i);
		++i;
	}
	return (NULL);
}
