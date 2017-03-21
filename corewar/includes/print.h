/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:33:54 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 15:06:16 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "corewar.h"
# include "args_parser.h"
# include "libft.h"

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

void				print_args_parser(t_parser *parser);
void				print_champion(t_champion *champion);
void				print_process_fd(int fd, const t_process *process);

#endif
