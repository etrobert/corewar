/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 20:02:25 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/08 16:50:48 by mverdier         ###   ########.fr       */
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
		endwin();
		return (0);
	}
	else if (ch == 'q' && visu->speed + 100 <= 50000)
		visu->speed += 100;
	else if (ch == 'w' && visu->speed + 1000 <= 50000)
		visu->speed += 1000;
	else if (ch == 'r' && visu->speed - 100 < 50000)
		visu->speed -= 100;
	else if (ch == 'e' && visu->speed - 1000 < 50000)
		visu->speed -= 1000;
	return (1);
}
