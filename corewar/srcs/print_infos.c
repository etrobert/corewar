/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:24:23 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/22 14:51:30 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void		print_name(t_visu *visu, t_champion *champ, int *i)
{
	char		*name;

	name = champ->header.prog_name;
	if (ft_strchr(name, '\n') &&
			ft_strchr(name, '\n') - name - 3 < INFOS_WIDTH - 13)
		mvwprintw(visu->infos, (*i)++, 2, "Player %u : %.*s...",
				champion_get_id(champ), ft_strchr(name, '\n') - name, name);
	else if (ft_strlen(name) - 3 > (unsigned long)INFOS_WIDTH - 13)
		mvwprintw(visu->infos, (*i)++, 2, "Player %u : %.*s...",
				champion_get_id(champ), INFOS_WIDTH - 17, name);
	else
		mvwprintw(visu->infos, (*i)++, 2, "Player %u : %s",
				champion_get_id(champ), name);
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

static void		print_winner_visu(t_corewar *corewar, t_visu *visu, int *i)
{
	t_champion	*winner;

	winner = corewar_get_winner(corewar);
	wattron(visu->infos, COLOR_PAIR(winner->id));
	mvwprintw(visu->infos, (*i)++, 2, "Player %u has won !", winner->id);
	wattroff(visu->infos, COLOR_PAIR(winner->id));
}

void			print_infos(t_corewar *corewar, t_visu *visu,
		t_list *champs)
{
	int			i;

	i = 1;
	if (corewar_end(corewar))
		print_winner_visu(corewar, visu, &i);
	else if (visu->pause)
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
