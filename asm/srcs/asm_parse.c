/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:54:22 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 18:07:44 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_parse(t_header **header, t_list *file)
{
	t_list_e		*line;
	int				name;
	int				comment;

	if (!asm_parse_init(header, file, &line))
		return (0);
	while (line)
	{
		if (!(name = asm_get_prog_name(line->val, header)) ||
				!(comment = asm_get_prog_comment(line->val, header)))
			return (0);
		if (name != NAME && comment != COMMENT)
			(*header)->prog_size += asm_get_line_size(line);
		line = line->next;
	}
	return (1);
}
