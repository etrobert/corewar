/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_go_to_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:54:07 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/08 18:58:02 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_skip_comment_and_empty(char **split, int *n, t_bytes **bytes)
{
	if (!split[*n])
	{
		asm_free_split(split);
		free(*bytes);
		return (1);
	}
	if (split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		free(*bytes);
		return (1);
	}
	return (0);
}

int			asm_go_to_instruct(char **split, int *n, t_bytes **bytes)
{
	int		lab;

	lab = 0;
	if (asm_skip_comment_and_empty(split, n, bytes))
		return (1);
	if (split[*n] && split[*n][ft_strlen(split[*n]) - 1] == LABEL_CHAR)
	{
		lab = 1;
		(*n)++;
	}
	if (!split[*n] || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
	{
		asm_free_split(split);
		free(*bytes);
		if (lab == 1 || split[*n][0] == COMMENT_CHAR || split[*n][0] == ';')
			return (1);
		return (0);
	}
	return (2);
}
