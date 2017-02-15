/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/12 20:20:11 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_endian.h"

void	print_bytes(int x)
{
	unsigned int		i;

	i = 0;
	while (i < sizeof(x))
	{
		ft_printf("%#.2x\n", ((char *)(&x))[i]);
		++i;
	}
}

int main(int argc, char **argv)
{
	int j;

	(void)argc;
	(void)argv;
	((char *)(&j))[0] = 1;
	((char *)(&j))[1] = 2;
	((char *)(&j))[2] = 3;
	((char *)(&j))[3] = 4;
	ft_printf("%d\n", ft_is_big_endian());
	print_bytes(j);
	ft_printf("SEPARATOR\n");
	print_bytes(ft_int32_big_endian(j));
	return (0);
}
