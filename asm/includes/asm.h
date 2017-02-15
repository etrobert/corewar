/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:54:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 17:59:31 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

# include <fcntl.h>
# include <unistd.h>

# define NAME			1
# define COMMENT		1
# define NOT_NAME		2
# define NOT_COMMENT	2
# define MAX_LEN		0

/*
**	file descriptors structure
*/

typedef struct	s_fd
{
	int			in;
	int			out;
}				t_fd;

/*
**	asm init
*/

int				asm_usage(int ac, char **av);
int				asm_open(char *filename);
int				asm_create(char *filename);

/*
**	read in .s
*/

int				asm_save_file(int fd, t_list **file);
int				asm_parse(t_header **header, t_list *file);
int				asm_parse_init(t_header **header, t_list *file, char **line);
int				asm_get_prog_name(char *str, t_header **header);
int				asm_get_prog_comment(char *str, t_header **header);

/*
**	write in .cor
*/

#endif
