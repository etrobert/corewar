/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:00:04 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/11 19:47:26 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_check_name_len(char *str, char **temp, int *len)
{
	if ((*len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
			> PROG_NAME_LENGTH)
	{
		ft_dprintf(2, "Champion name too long (Max length %d).\n",
				PROG_NAME_LENGTH);
		free(*temp);
		return (0);
	}
	return (1);
}

static int	asm_is_name(char *str)
{
	if (!ft_strstr(str, NAME_CMD_STRING) || (ft_strchr(str, COMMENT_CHAR) &&
				ft_strchr(str, COMMENT_CHAR) < ft_strstr(str, NAME_CMD_STRING))
			|| (ft_strchr(str, ';') &&
				ft_strchr(str, ';') < ft_strstr(str, NAME_CMD_STRING)))
		return (0);
	return (1);
}

static void	asm_multi_lines_name(char **str, char **temp, t_list_it *it,
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

int			asm_get_prog_name(char *str, t_asm *m_asm, t_list_it *it)
{
	int			len;
	char		*temp;

	temp = NULL;
	if (!asm_is_name(str))
		return (NOT_NAME);
	if (!ft_strchr(str, '"') ||
			ft_strstr(str, NAME_CMD_STRING) > ft_strchr(str, '"'))
	{
		ft_dprintf(2, "Syntax error in champion's name\n");
		return (0);
	}
	asm_multi_lines_name(&str, &temp, it, m_asm);
	if (!asm_check_name_len(str, &temp, &len))
		return (MAX_LEN);
	ft_memmove(m_asm->header->prog_name, ft_strchr(str, '"') + 1, len);
	m_asm->name = !m_asm->name;
	free(temp);
	return (NAME);
}
