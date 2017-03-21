/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:49 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/18 17:06:01 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_free_file(t_list *file)
{
	ft_list_apply(file, &free);
	ft_list_delete(file);
}
