/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:35:34 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/12 15:59:47 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_check_label_chars(t_labels **lab)
{
	int			i;
	t_labels	*label;

	label = *lab;
	i = 0;
	while (label->name[i])
		if (!ft_strchr(LABEL_CHARS, label->name[i++]))
		{
			ft_dprintf(2, "Bad char \'%c\' in label \'%s\'\n",
					label->name[i - 1], label->name);
			free((*lab)->name);
			free(*lab);
			return (0);
		}
	return (1);
}

int			asm_get_label(char **param, t_list **labels, unsigned int size,
		int *n)
{
	t_labels		*label;
	char			*tmp;

	if ((label = (t_labels*)malloc(sizeof(t_labels))) == NULL)
	{
		ft_dprintf(2, "Malloc error\n");
		return (0);
	}
	label->name = ft_strextract(*param, LABEL_CHAR);
	label->position = size;
	if (!asm_check_label_chars(&label))
		return (0);
	if (*(ft_strchr(*param, LABEL_CHAR) + 1) != '\0')
	{
		tmp = ft_strdup(*param);
		free(*param);
		*param = ft_strdup(ft_strchr(tmp, LABEL_CHAR) + 1);
		free(tmp);
	}
	else
		(*n)++;
	ft_list_push_back(*labels, label);
	return (1);
}
