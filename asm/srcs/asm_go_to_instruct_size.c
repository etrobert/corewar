/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_go_to_instruct_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:55:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/18 19:33:19 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_skip_comment_and_empty(char **split, int *n)
{
	if (!split[*n])
	{
		asm_free_split(split);
		return (0);
	}
	if (split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		return (0);
	}
	return (1);
}

int				asm_go_to_instruct_size(char **split, int *n, t_list **labels,
		unsigned int big_size)
{
	int		lab;

	lab = 0;
	if (!asm_skip_comment_and_empty(split, n))
		return (0);
	if (split[*n] && ft_strchr(split[*n], LABEL_CHAR))
	{
		lab = 1;
		if (!asm_get_label(&(split[*n]), labels, big_size, n))
		{
			asm_free_split(split);
			return (-1);
		}
	}
	if (!split[*n] || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		if (lab == 1 || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
			return (0);
		return (-1);
	}
	return (1);
}
