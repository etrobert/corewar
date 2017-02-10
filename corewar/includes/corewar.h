/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:03:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/10 17:05:29 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

typedef struct	s_corewar
{
	char		memory[MEM_SIZE];
	t_list		*processes;
}				t_corewar;

t_corewar		*corewar_new(??);
void			corewar_init(t_corewar *corewar, ??);
void			corewar_delete(t_corewar *corewar);

#endif
