/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:00:04 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 20:28:27 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_get_prog_name(char *str, t_header **header)
{
	int			len;

	if (ft_strstr(str, NAME_CMD_STRING))
	{
		if ((len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
				> PROG_NAME_LENGTH)
		{
			ft_dprintf(2, "Champion name too long (Max length %d).\n",
					PROG_NAME_LENGTH);
			return (MAX_LEN);
		}
		ft_memmove((*header)->prog_name, ft_strchr(str, '"') + 1, len);
		return (NAME);
	}
	return (NOT_NAME);
}
