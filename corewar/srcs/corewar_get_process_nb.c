/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_get_process_nb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:22:49 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/10 19:25:10 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_size_type			t_corewar_get_process_nb(t_corewar *corewar)
{
	return (ft_list_size(corewar->process));
}
