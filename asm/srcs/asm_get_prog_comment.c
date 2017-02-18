/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:03:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 20:28:54 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_get_prog_comment(char *str, t_header **header)
{
	int		len;

	if (ft_strstr(str, COMMENT_CMD_STRING))
	{
		if ((len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
				> COMMENT_LENGTH)
		{
			ft_dprintf(2, "Champion comment too long (Max length %d).\n",
					COMMENT_LENGTH);
			return (MAX_LEN);
		}
		ft_memmove((*header)->comment, ft_strchr(str, '"') + 1, len);
		return (COMMENT);
	}
	return (NOT_COMMENT);
}
