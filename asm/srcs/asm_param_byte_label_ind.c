/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_param_byte_label_ind.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:16:42 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/05 14:20:57 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_param_byte_label_ind(char *param, t_bytes **bytes_instruct,
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
		if (!strcmp(param, label->name))
		{
			bytes->param[i].s =
				ft_ushort16_big_endian(label->position - pos);
			bytes->param_size[i] = 2;
			return (1);
		}
		ft_list_it_inc(&it);
	}
	ft_dprintf(2, "Call to nonexistant label \'%s\'\n", param);
	return (0);
}
