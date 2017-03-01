/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_param_byte_label_dir.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:16:23 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/01 19:04:00 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_param_byte_label_dir(char *param, t_bytes **bytes_instruct,
		t_asm *m_asm, int i)
{
	t_list_it		it;
	t_labels		*label;
	t_op			*op_tab;
	unsigned int	pos;

	op_tab = get_op_by_code((*bytes_instruct)->op_c);
	pos = asm_get_pos(m_asm->instructs);
	it = ft_list_begin(m_asm->labels);
	while (!ft_list_it_end(m_asm->labels, it))
	{
		label = ft_list_it_get(m_asm->labels, it);
		if (!strcmp(param, label->name) && op_tab->small_direct == true)
		{
			(*bytes_instruct)->param[i].s =
				ft_ushort16_big_endian(label->position - pos);
			(*bytes_instruct)->param_size[i] = 2;
		}
		else if (!strcmp(param, label->name))
		{
			(*bytes_instruct)->param[i].i =
				ft_uint32_big_endian(label->position - pos);
			(*bytes_instruct)->param_size[i] = 4;
		}
		ft_list_it_inc(&it);
	}
}
