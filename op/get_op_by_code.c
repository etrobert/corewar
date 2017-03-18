/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_by_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:57:43 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/18 16:10:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op				*get_op_by_code(unsigned char op_code)
{
	int		i;

	i = 0;
	while (g_op_tab[i].op_code != op_code && g_op_tab[i].name != NULL)
		++i;
	return (g_op_tab + i);
}
