/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_is_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:49:24 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/20 20:28:28 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_labels	*asm_is_small_label(char *str, t_bytes *bytes, t_list *labels,
		int n)
{
	int			i;
	t_list_it	it;
	t_labels	*label;

	i = 0;
	if (!str)
		return (NULL);
	while (g_op_tab[i].op_code > 0 && g_op_tab[i].op_code != bytes->op_c)
		i++;
	if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR &&
			bytes->param_size[n] != 2)
		return (NULL);
	it = ft_list_begin(labels);
	label = ft_list_it_get(labels, it);
	while (!ft_list_it_end(labels, it) && ft_strcmp(str + 2, label->name))
	{
		ft_list_it_inc(&it);
		label = ft_list_it_get(labels, it);
	}
	return (label);
}

t_labels	*asm_is_big_label(char *str, t_bytes *bytes, t_list *labels,
		int n)
{
	int			i;
	t_list_it	it;
	t_labels	*label;

	i = 0;
	if (!str)
		return (NULL);
	while (g_op_tab[i].op_code > 0 && g_op_tab[i].op_code != bytes->op_c)
		i++;
	if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR &&
			bytes->param_size[n] != 4)
		return (NULL);
	it = ft_list_begin(labels);
	label = ft_list_it_get(labels, it);
	while (!ft_list_it_end(labels, it) && ft_strcmp(str + 2, label->name))
	{
		ft_list_it_inc(&it);
		label = ft_list_it_get(labels, it);
	}
	return (label);
}
