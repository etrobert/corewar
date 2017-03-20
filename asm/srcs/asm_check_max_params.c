/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_max_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:15:52 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/11 16:17:30 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_check_max_params(int i, t_op *op_tab, char **split, int n)
{
	if (i >= op_tab->nb_params || (i + 1 > op_tab->nb_params && split[n + i + 1]
				&& split[n + i + 1][0] != COMMENT_CHAR
				&& split[n + i + 1][0] != ';'))
	{
		ft_dprintf(2, "\'%s\' has too much params (take %d)\n",
				op_tab->name, op_tab->nb_params);
		return (0);
	}
	else if ((!split[n + i + 1] || (split[n + i + 1][0] == COMMENT_CHAR ||
				split[n + i + 1][0] == ';')) && i + 1 < op_tab->nb_params)
	{
		ft_dprintf(2, "\'%s\' has not enough params (take %d)\n",
				op_tab->name, op_tab->nb_params);
		return (0);
	}
	return (1);
}
