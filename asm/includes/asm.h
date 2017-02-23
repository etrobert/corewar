/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:54:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/23 15:52:58 by mverdier         ###   ########.fr       */
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

# define SMALL			1
# define BIG			2

/*
**	file descriptors structure
*/

typedef struct		s_fds
{
	int				in;
	int				out;
}					t_fds;

/*
**	struct to stock labels's relative positions
*/

typedef struct		s_labels
{
	char			*name;
	unsigned int	position;
}					t_labels;

/*
**	union to stock parameters into defferents sizes, for 1, 2 or 4 Bytes.
*/

typedef union		u_params
{
	unsigned char	c;
	unsigned short	s;
	unsigned int	i;
}					t_params;

/*
**	struct to stock all bytes of an instruction
*/

typedef struct		s_bytes
{
	unsigned char	op_c;
	int				op_c_size;
	unsigned char	ocp;
	int				ocp_size;
	t_params		param[3];
	int				param_size[3];
}					t_bytes;

/*
**	struct asm to stock ohters usefull structs
*/

typedef struct		s_asm
{
	t_list			*file;
	t_header		*header;
	t_list			*labels;
	t_list			*instructs;
}					t_asm;

/*
**	asm init
*/

int					asm_usage(int ac, char **av);
int					asm_open(char *filename);
int					asm_create(char *filename);

/*
**	read in .s (parsing)
*/

int					asm_save_file(int fd, t_asm *m_asm);

int					asm_get_size(t_asm *m_asm);
int					asm_get_prog_name(char *str, t_header **header);
int					asm_get_prog_comment(char *str, t_header **header);

int					asm_get_bytes(t_asm *m_asm);
void				asm_get_params(char **split, int n,
		t_bytes **bytes_instruct, t_asm *m_asm);

/*
**	write in .cor
*/

void				asm_write_bytes(int fd, t_asm m_asm);

#endif
