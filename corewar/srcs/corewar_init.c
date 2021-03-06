/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:36:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/21 10:44:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			add_fresh_process(t_corewar *corewar,
		t_reg_type pc, t_reg_type r1)
{
	t_process		*process;
	int				ret;

	if ((process = process_new()) == NULL)
		return (-1);
	process->pc = pc;
	process_set_reg(process, 1, r1);
	if ((ret = corewar_add_process(corewar, process)) < 0)
	{
		process_delete(process);
		return (ret);
	}
	return (FT_GOOD);
}

static int			load_one_champion(t_corewar *corewar,
		t_champion *champ, unsigned int pc, t_id_type id)
{
	corewar_write(corewar, (t_memory){champ->code, champ->header.prog_size},
			pc, id);
	if (add_fresh_process(corewar, pc, id) == -1)
		return (-1);
	champ->intern_id = id;
	corewar->last_living_champ = champ;
	return (0);
}

static int			load_champions(t_corewar *corewar, t_list *champions)
{
	t_list_it		it;
	t_champion		*champ;
	t_id_type		id;
	int				ret;

	id = 1;
	it = ft_list_begin(champions);
	while (!ft_list_it_end(champions, it))
	{
		champ = (t_champion *)(ft_list_it_get(champions, it));
		if ((ret = load_one_champion(corewar, champ,
						(id - 1) * MEM_SIZE / ft_list_size(champions), id)) < 0)
			return (ret);
		ft_list_it_inc(&it);
		++id;
	}
	return (0);
}

int					corewar_init(t_corewar *corewar, t_list *champions,
		int fd)
{
	int				ret;

	if (corewar == NULL)
		return (0);
	if ((corewar->process = ft_list_new()) == NULL)
		return (-1);
	if ((corewar->memory = ft_cbuff_new(MEM_SIZE)) == NULL)
		return (-1);
	ft_cbuff_clean(corewar->memory);
	if ((corewar->memory_id = ft_cbuff_new(MEM_SIZE)) == NULL)
		return (-1);
	ft_cbuff_clean(corewar->memory_id);
	corewar->last_proc_id = 1;
	if ((ret = load_champions(corewar, champions)) != FT_GOOD)
		return (ret);
	corewar->cycle = 0;
	corewar->last_check = 0;
	corewar->cycles_to_die = CYCLE_TO_DIE;
	corewar->clear_checks = 0;
	corewar->nbr_live = 0;
	corewar->fd = fd;
	corewar->verbosity = CW_VB_INIT;
	corewar->print_aff = true;
	corewar->champions = champions;
	return (FT_GOOD);
}
