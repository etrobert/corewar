/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_param_byte_label_dir.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:16:23 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/02 19:11:36 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_param_byte_label_dir(char *param, t_bytes **bytes_instruct,
		t_asm *m_asm, int i)
{
	t_list_it		it;
	t_labels		*label;
	unsigned int	pos;
	t_bytes			*bytes;

	bytes = *bytes_instruct;
	pos = asm_get_pos(m_asm->instructs);
	it = ft_list_begin(m_asm->labels);
	while (!ft_list_it_end(m_asm->labels, it))
	{
		label = ft_list_it_get(m_asm->labels, it);
		if (!strcmp(param, label->name) && bytes->op_tab->small_direct == true)
		{
			bytes->param[i].s =
				ft_ushort16_big_endian(label->position - pos);
			bytes->param_size[i] = 2;
		}
		else if (!strcmp(param, label->name))
		{
			bytes->param[i].i =
				ft_uint32_big_endian(label->position - pos);
			bytes->param_size[i] = 4;
		}
		ft_list_it_inc(&it);
	}
}
