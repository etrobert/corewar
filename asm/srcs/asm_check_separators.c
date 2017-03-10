/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_separators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:56:32 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/10 20:17:13 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_separator_misplaced(char *str)
{
	if (ft_strchr(split[i], SEPARATOR_CHAR))
	{
		ft_dprintf(2, "Separator char misplaced in \'%s\'\n", split[i]);
		return (0);
	}
	return (1);
}

int		asm_check_separators(char *line, t_op *op_tab)
{
	char	**split;
	int		i;

	if (!(split = ft_strsplit_str(line, " \t")))
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	i = 0;
	while (ft_strcmp(split[i], op_tab->name))
	{
		if (!asm_separator_misplaced(split[i]))
			return (0);
		i++;
	}
	if (!asm_separator_misplaced(split[i]))
		return (0);
	i++;
}
