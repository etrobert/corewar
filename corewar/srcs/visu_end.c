/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:58:58 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 17:18:21 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	visu_end(t_visu *visu, t_parser *parser)
{
	delwin(visu->board);
	delwin(visu->infos);
	if (parser->console)
	{
		delwin(visu->log);
		delwin(visu->log_border);
	}
	endwin();
}
