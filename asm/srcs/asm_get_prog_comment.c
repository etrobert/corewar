/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:03:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/09 15:55:09 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_get_prog_comment(char *str, t_asm *m_asm, t_list_it *it)
{
	int		len;
	char	*tmp;
	char	*temp;

	temp = NULL;
	if (!ft_strstr(str, COMMENT_CMD_STRING))
		return (NOT_COMMENT);
	if (!ft_strchr(str, '"') ||
			ft_strstr(str, COMMENT_CMD_STRING) > ft_strchr(str, '"'))
	{
		ft_dprintf(2, "Syntax error in champion's comment\n");
		return (0);
	}
	while (ft_strchr(str, '"') == ft_strrchr(str, '"'))
	{
		ft_list_it_inc(it);
		tmp = ft_strjoin("\n", ft_list_it_get(m_asm->file, *it));
		temp = ft_strjoin(str, tmp);
		free(tmp);
		str = temp;
	}
	if ((len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
			> COMMENT_LENGTH)
	{
		ft_dprintf(2, "Champion comment too long (Max length %d).\n",
				COMMENT_LENGTH);
		free(temp);
		return (MAX_LEN);
	}
	ft_memmove(m_asm->header->comment, ft_strchr(str, '"') + 1, len);
	free(temp);
	return (COMMENT);
}
