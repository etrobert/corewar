/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 20:02:25 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/13 15:16:18 by mverdier         ###   ########.fr       */
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
		return (0);
	}
	else if (ch == 'q' && visu->speed + 1000 <= 1000000)
		visu->speed += 1000;
	else if (ch == 'w' && visu->speed + 100 <= 1000000)
		visu->speed += 100;
	else if (ch == 'r' && visu->speed - 1000 < 1000000)
		visu->speed -= 1000;
	else if (ch == 'e' && visu->speed - 100 < 1000000)
		visu->speed -= 100;
	return (1);
}
