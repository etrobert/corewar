/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_get_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:03:35 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 19:21:16 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char				ocp_get_type(unsigned char ocp, int id)
{
	return ((ocp >> ((3 - id) * 2)) & 0b11);
}
