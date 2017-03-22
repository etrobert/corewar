/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:09:29 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 14:21:00 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	free_params(t_list *champs, t_corewar *cw, t_parser *parser)
{
	parser_delete(parser);
	ft_list_apply(champs, (t_f_apply)(&champion_delete));
	ft_list_delete(champs);
	corewar_delete(cw);
}
