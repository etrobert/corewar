/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:00:04 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/03 15:50:47 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_get_prog_name(char *str, t_header **header)
{
	int			len;
	char		**split;

	split = NULL;
	if ((ft_strchr(str, ' ') || ft_strchr(str, '\t'))
			&& !(split = ft_strsplit_str(str, " \t")))
		return (0);
	else if (!ft_strchr(str, ' ') && !ft_strchr(str, '\t'))
		return (NOT_NAME);
	if (!ft_strcmp(split[0], NAME_CMD_STRING))
	{
		if ((len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
				> PROG_NAME_LENGTH)
		{
			ft_dprintf(2, "Champion name too long (Max length %d).\n",
					PROG_NAME_LENGTH);
			asm_free_split(split);
			return (MAX_LEN);
		}
		ft_memmove((*header)->prog_name, ft_strchr(str, '"') + 1, len);
		return (NAME);
	}
	asm_free_split(split);
	return (NOT_NAME);
}
