/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:03:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/03 15:50:27 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_get_prog_comment(char *str, t_header **header)
{
	int		len;
	char	**split;

	split = NULL;
	if ((ft_strchr(str, ' ') || ft_strchr(str, '\t'))
			&& !(split = ft_strsplit_str(str, " \t")))
		return (0);
	else if (!ft_strchr(str, ' ') && !ft_strchr(str, '\t'))
		return (NOT_COMMENT);
	if (!ft_strcmp(split[0], COMMENT_CMD_STRING))
	{
		if ((len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
				> COMMENT_LENGTH)
		{
			ft_dprintf(2, "Champion comment too long (Max length %d).\n",
					COMMENT_LENGTH);
			asm_free_split(split);
			return (MAX_LEN);
		}
		ft_memmove((*header)->comment, ft_strchr(str, '"') + 1, len);
		return (COMMENT);
	}
	asm_free_split(split);
	return (NOT_COMMENT);
}
