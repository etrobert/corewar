/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_get_byte_champ.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:17:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 20:31:18 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion			*corewar_get_byte_champ(t_corewar *corewar,
		unsigned int pos)
{
	if (corewar == NULL)
		return (NULL);
	return (corewar_id_champ(corewar, corewar_get_byte_id(corewar, pos)));
}
