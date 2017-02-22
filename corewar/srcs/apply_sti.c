/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 00:00:49 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/19 00:46:39 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//Comparer avec le vrai. Prend il un registre sans se poser de question ou
//analyse til locp et fait rien parce qerreur ?

size_t				read_param(t_corewar, t_process *process,
		t_param_type type, t_param *param)
{
	if (type == REG_CODE)
	{
		ft_cbuff_read(corewar->memory, &(param.c), process->pc, 1);
		return (1);
	}
	else if (type == DIR_CODE)
	{
		ft_cbuff_read(corewar->memory, &(param.
	}
}

void				apply_sti(t_corewar *corewar, t_process *process)
{	
	char			ocp;
	t_param			params[3];

	ft_cbuff_read(corewar->memory, &ocp, process->pc, sizeof(unsigned char));
	++(process->pc);
	ft_cbuff_read(corewar->memory, &(params[0]->c),
			process->pc, sizeof(unsigned char));
	++(process->pc);
	if ((ocp >> 2) & 255 == REG_CODE)
	else if ((ocp >> 2) & 255 == DIR_CODE)
	else

}
