/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_by_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:57:43 by etrobert          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/03/18 16:10:53 by etrobert         ###   ########.fr       */
=======
/*   Updated: 2017/03/02 15:29:42 by mverdier         ###   ########.fr       */
>>>>>>> 8a8d3a19f6c18e31bad79e765e35765bd14b05d8
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
