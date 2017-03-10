/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_complete_ocp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:20:04 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/08 18:24:40 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_complete_ocp(t_bytes **bytes, int i)
{
	while ((*bytes)->op_tab->ocp == true && i < 3)
	{
		(*bytes)->ocp <<= 2;
		i++;
	}
}