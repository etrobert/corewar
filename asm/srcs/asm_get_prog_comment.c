/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:03:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/18 18:47:35 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_check_comment_len(char *str, char **temp, int *len)
{
	if ((*len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
			> COMMENT_LENGTH)
	{
		ft_dprintf(2, "Champion comment too long (Max length %d).\n",
				COMMENT_LENGTH);
		free(*temp);
		return (0);
	}
	return (1);
}

static int	asm_is_comment(char *str)
{
	if (!ft_strstr(str, COMMENT_CMD_STRING) || (ft_strchr(str, COMMENT_CHAR) &&
				ft_strchr(str, COMMENT_CHAR) <
				ft_strstr(str, COMMENT_CMD_STRING)) || (ft_strchr(str, ';') &&
				ft_strchr(str, ';') < ft_strstr(str, COMMENT_CMD_STRING)))
		return (0);
	return (1);
}

static void	asm_multi_lines_comment(char **str, char **temp, t_list_it *it,
		t_asm *m_asm)
{
	char	*tmp;

	while (ft_strchr(*str, '"') == ft_strrchr(*str, '"'))
	{
		ft_list_it_inc(it);
		tmp = ft_strjoin("\n", ft_list_it_get(m_asm->file, *it));
		*temp = ft_strjoin(*str, tmp);
		free(tmp);
		*str = *temp;
	}
}

static int	asm_check_comment_syntax(char *str, char **split)
{
	if (!ft_strchr(str, '"') ||
			ft_strstr(str, COMMENT_CMD_STRING) > ft_strchr(str, '"') ||
			ft_strcmp(split[0], COMMENT_CMD_STRING) || split[1][0] != '"')
	{
		ft_dprintf(2, "Syntax error in champion's comment\n");
		asm_free_split(split);
		return (0);
	}
	return (1);
}

int			asm_get_prog_comment(char *str, t_asm *m_asm, t_list_it *it)
{
	int		len;
	char	*temp;
	char	**split;

	temp = NULL;
	if (!asm_is_comment(str))
		return (NOT_COMMENT);
	if (!(split = ft_strsplit_str(str, " \t")))
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	if (!asm_check_comment_syntax(str, split))
		return (0);
	asm_free_split(split);
	asm_multi_lines_comment(&str, &temp, it, m_asm);
	if (!asm_check_comment_len(str, &temp, &len))
		return (MAX_LEN);
	ft_memmove(m_asm->header->comment, ft_strchr(str, '"') + 1, len);
	m_asm->comment = !m_asm->comment;
	free(temp);
	return (COMMENT);
}
