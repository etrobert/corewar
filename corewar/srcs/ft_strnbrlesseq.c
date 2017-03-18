/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbrlesseq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:29:46 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/16 19:31:44 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	ft_strnbrlesseq_cmp(char *nbr1, char *nbr2, bool rev)
{
	int		i;

	i = 0;
	while (nbr1[i] != '\0' && nbr2[i] != '\0')
	{
		if (nbr1[i] > nbr2[i])
			return (rev ? true : false);
		if (nbr1[i] < nbr2[i])
			return (rev ? false : true);
		++i;
	}
	if (nbr1[i] == '\0' && nbr2[i] == '\0')
		return (true);
	return (false);
}

bool		ft_strnbrlesseq(char *nbr1, char *nbr2)
{
	int		i;
	bool	rev;
	size_t	len[2];

	i = 0;
	rev = false;
	if (*nbr1 == '-' && *nbr2 != '-')
		return (true);
	else if (*nbr1 != '-' && *nbr2 == '-')
		return (false);
	else if (*nbr1 == '-' && *nbr2 == '-')
		rev = true;
	len[0] = ft_strlen(nbr1);
	len[1] = ft_strlen(nbr2);
	if (len[0] > len[1])
		return (rev ? true : false);
	else if (len[1] > len[0])
		return (rev ? false : true);
	return (ft_strnbrlesseq_cmp(nbr1, nbr2, rev));
}
