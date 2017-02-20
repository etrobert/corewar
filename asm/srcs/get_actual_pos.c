/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_actual_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:06:16 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/20 18:46:12 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	asm_get_actual_pos(t_bytes *bytes)
{
	static unsigned int	pos = 0;
	int					i;

	pos += bytes->op_c_size;
	pos += bytes->ocp_size;
	i = 0;
	while (i < 3)
		pos += bytes->param_size[i++];
	ft_printf("pos = %u\n", pos);
	return (pos);
}
