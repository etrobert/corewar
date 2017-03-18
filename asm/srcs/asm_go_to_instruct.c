/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_go_to_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:54:07 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/11 18:20:46 by mverdier         ###   ########.fr       */
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

static int	asm_no_instruct_or_comment(char **split, int n, t_bytes **bytes,
		int lab)
{
	if (!split[n] || split[n][0] == COMMENT_CHAR || split[n][0] == ';')
	{
		asm_free_split(split);
		free(*bytes);
		if (lab == 1 || split[n][0] == COMMENT_CHAR || split[n][0] == ';')
			return (1);
		return (0);
	}
	return (2);
}

int			asm_go_to_instruct(char **split, int *n, t_bytes **bytes)
{
	int		lab;
	int		ret;
	char	*tmp;

	lab = 0;
	if (asm_skip_comment_and_empty(split, n, bytes))
		return (1);
	if (split[*n] && ft_strchr(split[*n], LABEL_CHAR))
	{
		if (*(ft_strchr(split[*n], LABEL_CHAR) + 1) != '\0')
		{
			tmp = ft_strdup(split[*n]);
			free(split[*n]);
			split[*n] = ft_strdup(ft_strchr(tmp, LABEL_CHAR) + 1);
			free(tmp);
		}
		else
			(*n)++;
		lab = 1;
	}
	if ((ret = asm_no_instruct_or_comment(split, *n, bytes, lab)) < 2)
		return (ret);
	return (2);
}
