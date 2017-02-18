/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 00:00:49 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/19 00:08:33 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//Comparer avec le vrai. Prend il un registre sans se poser de question ou
//analyse til locp et fait rien parce qerreur ?

void				apply_sti(t_corewar *corewar, t_process *process)
{	
	unsigned char	ocp;

	ft_cbuff_read(corewar->memory, &ocp, process->pc, sizeof(unsigned char));
	++process->pc;

}
