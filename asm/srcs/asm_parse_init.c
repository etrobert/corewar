/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:34:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 18:08:14 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_parse_init(t_header **header, t_list *file, char **line)
{
	(*line) = file->first;
	if (((*header) = (t_header*)malloc(sizeof(t_header))) == NULL)
		return (0);
	ft_bzero((*header)->prog_name, PROG_NAME_LENGTH + 2);
	ft_bzero((*header)->comment, COMMENT_LENGTH + 2);
	(*header)->magic = ft_int32_big_endian(COREWAR_EXEC_MAGIC);
	(*header)->prog_size = 0;
	return (1);
}
