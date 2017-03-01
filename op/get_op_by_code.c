/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_by_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:57:43 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/01 17:17:29 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op				*get_op_by_code(unsigned char op_code)
{
	int		i;

	i = 0;
	while (g_op_tab[i].op_code != op_code && g_op_tab[i].name != NULL)
		++i;
	if (g_op_tab[i].name != NULL)
		return (g_op_tab + i);
	return (NULL);
}
