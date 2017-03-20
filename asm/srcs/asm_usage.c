/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:00 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/18 16:43:57 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_usage(int ac, char **av)
{
	char	*ret;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!(ret = ft_strrchr(av[i], '.')) || ft_strcmp(ret, ".s"))
		{
			ft_printf("Usage : %s [filename].s\n", av[0]);
			return (0);
		}
		i++;
	}
	return (1);
}
