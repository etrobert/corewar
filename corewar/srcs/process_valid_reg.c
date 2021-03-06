/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_valid_reg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 20:30:34 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/11 20:35:29 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

bool				process_valid_reg(unsigned char reg)
{
	return (reg >= 1 && reg <= REG_NUMBER);
}
