/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:40:35 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/02 19:09:55 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	asm_get_pos(t_list *instructs)
{
	t_list_it		it;
	unsigned int	pos;
	int				i;
	t_bytes			*bytes;

	pos = 0;
	it = ft_list_begin(instructs);
	while (!ft_list_it_end(instructs, it))
	{
		bytes = ft_list_it_get(instructs, it);
		pos += 1;
		pos += bytes->ocp_size;
		i = 0;
		while (i < 3)
			pos += bytes->param_size[i++];
		ft_list_it_inc(&it);
	}
	return (pos);
}
