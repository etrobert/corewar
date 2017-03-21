/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:24:23 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/21 15:01:28 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void		print_name(t_visu *visu, t_champion *champ, int *i)
{
	char		*name;

	name = champ->header.prog_name;
	if (ft_strchr(name, '\n') &&
			ft_strchr(name, '\n') - name - 3 < COLS - (3 * PRINT_WIDTH + 16))
		mvwprintw(visu->infos, (*i)++, 13, "%.*s...",
				ft_strchr(name, '\n') - name, name);
	else if (ft_strlen(name) - 3 >
			(unsigned long)COLS - (3 * PRINT_WIDTH + 16))
		mvwprintw(visu->infos, (*i)++, 13, "%.*s..."
				, COLS - (3 * PRINT_WIDTH + 20), name);
	else
		mvwprintw(visu->infos, (*i)++, 13, "%s", name);
}

static void		print_players(t_visu *visu,
		t_list *champs, int i)
{
	t_list_it	it;
	t_champion	*champ;
	int			p_number;
	int			n;

	p_number = ft_list_size(champs);
	it = ft_list_begin(champs);
	n = 0;
	while (n < p_number)
	{
		champ = ft_list_it_get(champs, it);
		mvwprintw(visu->infos, i, 2, "Player %u : ", champion_get_id(champ));
		wattron(visu->infos, COLOR_PAIR(n + 1));
		print_name(visu, champ, &i);
		wattroff(visu->infos, COLOR_PAIR(n + 1));
		mvwprintw(visu->infos, i++, 2, "Last live :               %u",
				champion_get_last_live(champ));
		mvwprintw(visu->infos, i++, 2, "Lives in current period : %u",
				champion_get_period_lives(champ));
		i++;
		n++;
		ft_list_it_inc(&it);
	}
}

void			print_infos(t_corewar *corewar, t_visu *visu,
		t_list *champs)
{
	int			i;

	i = 1;
	if (visu->pause)
		mvwprintw(visu->infos, i++, 2, "PAUSED");
	else
		mvwprintw(visu->infos, i++, 2, "PLAY");
	if (visu->speed == 0)
		mvwprintw(visu->infos, i++, 2, "speed limit : %u cycles/s", 1000);
	else
		mvwprintw(visu->infos, i++, 2, "speed limit : %u cycles/s",
				1000000 / visu->speed);
	mvwprintw(visu->infos, i++, 2, "cycle : %u", corewar_get_cycle(corewar));
	mvwprintw(visu->infos, i++, 2, "process : %u",
			corewar_get_process_nb(corewar));
	mvwprintw(visu->infos, i++, 2, "cycle_to_die : %u",
			corewar_get_cycles_to_die(corewar));
	i++;
	print_players(visu, champs, i);
}
