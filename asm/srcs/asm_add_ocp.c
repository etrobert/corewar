/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_add_ocp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:30:16 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/11 16:30:54 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_add_ocp(t_bytes **bytes_instruct, unsigned char code)
{
	t_bytes		*bytes;

	bytes = *bytes_instruct;
	if (bytes->op_tab->ocp == true)
	{
		bytes->ocp += code;
		bytes->ocp <<= 2;
		bytes->ocp_size = 1;
	}
}
