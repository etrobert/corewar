/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_separators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:56:32 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/11 17:30:24 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*asm_dup_without_space(char *src, char *dest)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (src[i])
	{
		if (!ft_isspace(src[i]))
			dest[n++] = src[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

static int	asm_no_space_len(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			len++;
		i++;
	}
	return (len);
}

static char	*asm_remove_space(char *line, t_op *op_tab)
{
	char	*str;
	char	*tmp;
	int		len;

	tmp = ft_strstr(line, op_tab->name) + ft_strlen(op_tab->name);
	len = asm_no_space_len(tmp);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str = asm_dup_without_space(tmp, str);
	return (str);
}

static int	asm_check_params_separators(char *tmp, char *line, int *sep, int i)
{
	while (tmp[i])
	{
		if (tmp[i] == SEPARATOR_CHAR && (tmp[i + 1] == SEPARATOR_CHAR
					|| tmp[i + 1] == '\0'))
		{
			ft_dprintf(2, "Separator char misplaced in \'%s\'\n", line);
			return (0);
		}
		else if (tmp[i] == SEPARATOR_CHAR)
			(*sep)++;
		i++;
	}
	return (1);
}

int			asm_check_separators(char *line, t_op *op_tab)
{
	char	*tmp;
	int		i;
	int		sep;

	tmp = asm_remove_space(line, op_tab);
	sep = 0;
	i = 0;
	if (tmp[i] == SEPARATOR_CHAR)
	{
		ft_dprintf(2, "Separator char misplaced in \'%s\'\n", line);
		free(tmp);
		return (0);
	}
	if (!asm_check_params_separators(tmp, line, &sep, i))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (sep != op_tab->nb_params - 1)
	{
		ft_dprintf(2, "Params are badly separated in \'%s\'\n", line);
		return (0);
	}
	return (1);
}
