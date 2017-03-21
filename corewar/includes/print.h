/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:33:54 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 15:35:12 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "corewar.h"
# include "libft.h"

# define DUMP_WIDTH		32

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

void				print_champion(t_champion *champion);
void				print_process_fd(int fd, const t_process *process);
void				print_champs(t_list *champs);
void				dump_corewar(const t_corewar *corewar);

#endif
