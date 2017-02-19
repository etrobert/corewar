/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_actual_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:06:16 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/19 20:15:23 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	asm_get_actual_pos(t_list *bytes_instructs)
{
	t_list_it			it;
	t_bytes				*bytes;
	int					i;
	static unsigned int	pos = 0;

	if ((it = ft_list_begin(bytes_instructs)) == NULL)
		return (pos);
	while (!ft_list_it_end(bytes_instructs, it))
		ft_list_it_inc(&it);
	bytes = ft_list_it_get(bytes_instructs, it);
	pos += bytes->op_c_size;
	pos += bytes->ocp_size;
	i = 0;
	while (i < 3)
		pos += bytes->param_size[i++];
	return (pos);
}
