/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:33:02 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/16 00:54:16 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

int					champion_init(t_champion *champ, t_id_type id, int fd)
{
	if (champ == NULL)
		return (0);
	if (read(fd, &(champ->header), sizeof(t_header)) <
			(ssize_t)sizeof(t_header))
		return (-1);
	champ->header.magic = ft_int32_big_endian(champ->header.magic);
	champ->header.prog_size =
		ft_int32_big_endian(champ->header.prog_size);
	champ->id = id;
	if ((champ->code = (unsigned char *)malloc(champ->header.prog_size))
			== NULL)
		return (-1);
	if (read(fd, champ->code, champ->header.prog_size) <
			champ->header.prog_size)
	{
		free(champ->code);
		return (-1);
	}
	return (0);
}
