/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:00:04 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/06 18:37:46 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_get_prog_name(char *str, t_asm *m_asm, t_list_it *it)
{
	int			len;

	if (!ft_strstr(str, NAME_CMD_STRING))
		return (NOT_NAME);
	if (!ft_strchr(str, '"') ||
			ft_strstr(str, NAME_CMD_STRING) > ft_strchr(str, '"'))
	{
		ft_dprintf(2, "Syntax error in champion's name\n");
		return (0);
	}
	while (ft_strchr(str, '"') == ft_strrchr(str, '"'))
	{
		ft_list_it_inc(it);
		str = ft_strjoin(str, "\n");
		str = ft_strjoin(str, ft_list_it_get(m_asm->file, *it));
	}
	if ((len = ft_strrchr(str, '"') - (ft_strchr(str, '"') + 1))
			> PROG_NAME_LENGTH)
	{
		ft_dprintf(2, "Champion name too long (Max length %d).\n",
				PROG_NAME_LENGTH);
		return (MAX_LEN);
	}
	ft_memmove(m_asm->header->prog_name, ft_strchr(str, '"') + 1, len);
	return (NAME);
}
