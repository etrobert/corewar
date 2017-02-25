/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:36:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/25 21:08:10 by mverdier         ###   ########.fr       */
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
	process->regs[1] = r1;
	if ((ret = corewar_add_process(corewar, process)) < 0)
	{
		process_delete(process);
		return (ret);
	}
	return (0);
}

static int			load_one_champion(t_corewar *corewar,
		const t_champion *champ, unsigned int pc)
{
	ft_cbuff_write(corewar->memory, champ->code, pc, champ->header.prog_size);
	if (add_fresh_process(corewar, champ->id, pc) == -1)
		return (-1);
	return (0);
}

static int			load_champions(t_corewar *corewar, const t_list *champions)
{
	t_list_it		it;
	t_champion		*champ;
	t_id_type		id;
	int				ret;

	id = 0;
	it = ft_list_begin(champions);
	while (!ft_list_it_end(champions, it))
	{
		champ = (t_champion *)(ft_list_it_get(champions, it));
		if ((ret = load_one_champion(corewar, champ,
						id * MEM_SIZE / ft_list_size(champions))) < 0)
			return (ret);
		ft_list_it_inc(&it);
		++id;
	}
	return (FT_GOOD);
}

int					corewar_init(t_corewar *corewar, const t_list *champions)
{
	int				ret;

	if (corewar == NULL)
		return (0);
	if ((corewar->process = ft_list_new()) == NULL)
		return (-1);
	if ((corewar->memory = ft_cbuff_new(MEM_SIZE)) == NULL)
		return (-1);
	if ((ret = load_champions(corewar, champions)) != FT_GOOD)
		return (ret);
	corewar->cycle = 0;
	corewar->last_check = 0;
	corewar->cycles_to_die = CYCLE_TO_DIE;
	corewar->clear_checks = 0;
	corewar->nbr_live = 0;
	return (0);
}
