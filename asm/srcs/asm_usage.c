/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:00 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/12 20:39:16 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"

int		asm_usage(int ac, char **av)
{
	char	*ret;

	if (ac != 2 || !(ret = ft_strrchr(av[1], '.')) || ft_strcmp(ret, ".s\0"))
	{
		ft_printf("Usage : %s [filename].s\n", av[0]);
		return (0);
	}
	return (1);
}
