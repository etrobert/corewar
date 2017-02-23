/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_actual_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:06:16 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/20 19:28:22 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	asm_get_actual_pos(t_list *bytes_instructs, t_bytes *bytes)
{
	int			pos;
	int			i;
	t_list_it	it;
	t_bytes		*byte;

	(void)bytes;
	pos = 0;
	it = ft_list_begin(bytes_instructs);
	while (!ft_list_it_end(bytes_instructs, it))
	{
		byte = ft_list_it_get(bytes_instructs, it);
		pos += byte->op_c_size;
		pos += byte->ocp_size;
		i = 0;
		while (i < 3)
			pos += byte->param_size[i++];
		ft_list_it_inc(&it);
	}
	ft_printf("pos = %d\n", pos);
	return (pos);
}
