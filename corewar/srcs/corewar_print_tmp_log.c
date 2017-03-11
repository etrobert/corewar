/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_print_tmp_log.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:45:14 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/10 19:46:29 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				corewar_print_tmp_log(t_corewar *corewar, char *str)
{
	corewar_print_log(corewar, str);
	free(str);
}
