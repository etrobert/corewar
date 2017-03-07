/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:54:05 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/06 18:30:18 by mverdier         ###   ########.fr       */
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
	t_op			*op_tab;
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
int					asm_get_params_size(char **split, int n, t_op *op_tab);
int					asm_get_prog_name(char *str, t_asm *m_asm, t_list_it *it);
int					asm_get_prog_comment(char *str, t_asm *m_asm,
		t_list_it *it);
unsigned int		asm_get_line_size(char *line, t_list **labels,
		unsigned int big_size);

int					asm_get_bytes(t_asm *m_asm);
int					asm_get_params(char **split, int n,
		t_bytes **bytes_instruct, t_asm *m_asm);
unsigned int		asm_get_pos(t_list *instructs);
int					asm_param_byte_label_dir(char *param,
		t_bytes **bytes_instruct, t_asm *m_asm, int i);
int					asm_param_byte_label_ind(char *param,
		t_bytes **bytes_instruct, t_asm *m_asm, int i);

/*
**	write in .cor
*/

void				asm_write_bytes(int fd, t_asm m_asm, char *filename);

/*
**	free functions
*/

void				asm_free_split(char **split);

#endif
