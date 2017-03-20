/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 20:02:25 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/20 13:41:27 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		play_events(t_visu *visu)
{
	int		ch;

	if ((ch = getch()) == ' ')
		visu->pause = !visu->pause;
	else if (ch == 27)
	{
		visu_end(visu);
		return (1);
	}
	else if (ch == 'r' && 1000000 / visu->speed <= 990)
		visu->speed = 1000000 / ((1000000 / visu->speed) + 10);
	else if (ch == 'r' && 1000000 / visu->speed > 990 && visu->speed > 1000)
		visu->speed = 1000;
	else if (ch == 'e' && 1000000 / visu->speed <= 999)
		visu->speed = 1000000 / ((1000000 / visu->speed) + 1);
	else if (ch == 'q' && 1000000 / visu->speed >= 11)
		visu->speed = 1000000 / ((1000000 / visu->speed) - 10);
	else if (ch == 'q' && 1000000 / visu->speed <= 10 && visu->speed < 1000000)
		visu->speed = 1000000;
	else if (ch == 'w' && 1000000 / visu->speed >= 2)
		visu->speed = 1000000 / ((1000000 / visu->speed) - 1);
	return (0);
}
