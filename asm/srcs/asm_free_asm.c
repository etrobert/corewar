/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:20:56 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/18 17:53:36 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_free_labels_name(void *label)
{
	t_labels	*tmp;

	tmp = label;
	free(tmp->name);
	free(tmp);
}

void		asm_free_asm(t_asm *m_asm)
{
	asm_free_file(m_asm->file);
	free(m_asm->header);
	ft_list_apply(m_asm->labels, &asm_free_labels_name);
	ft_list_delete(m_asm->labels);
	ft_list_apply(m_asm->instructs, &free);
	ft_list_delete(m_asm->instructs);
}
