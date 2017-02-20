/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_param_byte_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:46:42 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/19 20:57:32 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_param_byte_label_sm(char *param,
		t_bytes **bytes_instruct, t_list *labels, int pos)
{
	t_bytes			*bytes;
	t_list_it		it;
	t_labels		*label;

	param = ft_strchr(param, LABEL_CHAR) + 1;
	it = ft_list_begin(labels);
	label = ft_list_it_get(labels, it);
	while (!ft_list_it_end(labels, it) && ft_strcmp(param, label->name))
	{
		ft_list_it_inc(&it);
		label = ft_list_it_get(labels, it);
	}
	bytes->param[i].s = ft_ushort16_big_endian(label->position - pos);
}

void			asm_param_byte_label_big(char *param,
		t_bytes **bytes_instruct, t_list *labels, int pos)
{
	t_bytes			*bytes;
	t_list_it		it;
	t_labels		*label;

	bytes = *bytes_instruct;
	param = ft_strchr(param, LABEL_CHAR) + 1;
	it = ft_list_begin(labels);
	label = ft_list_it_get(labels, it);
	while (!ft_list_it_end(labels, it) && ft_strcmp(param, label->name))
	{
		ft_list_it_inc(&it);
		label = ft_list_it_get(labels, it);
	}
	bytes->param[i].i = ft_uint32_big_endian(label->position - pos);
}
