/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_is_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:49:24 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/19 21:29:11 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_labels	*asm_is_small_label(char *str, t_bytes *bytes, t_list *labels)
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
			g_op_tab[i].small_direct == false)
		return (NULL);
	it = ft_list_begin(labels);
	label = ft_list_it_get(labels, it);
	while (!ft_list_it_end(labels, it) && ft_strcmp(str, label->name))
	{
		ft_list_it_inc(&it);
		label = ft_list_it_get(labels, it);
	}
	return (label);
}

t_labels	*asm_is_big_label(char *str, t_bytes *bytes, t_list *labels)
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
			g_op_tab[i].small_direct == true)
		return (NULL);
	it = ft_list_begin(labels);
	label = ft_list_it_get(labels, it);
	while (!ft_list_it_end(labels, it) && ft_strcmp(str, label->name))
	{
		ft_list_it_inc(&it);
		label = ft_list_it_get(labels, it);
	}
	return (label);
}
