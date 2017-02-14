/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:33:02 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/14 20:25:13 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

int					champion_init(t_champion *champion, t_id_type id, int fd)
{
	if (champion == NULL)
		return (0);
	if (read(fd, &(champion->header), sizeof(t_header)) <
			(ssize_t)sizeof(t_header))
		return (-1);
	champion->header.magic = ft_int32_big_endian(champion->header.magic);
	champion->header.prog_size =
		ft_int32_big_endian(champion->header.prog_size);
	champion->id = id;
	if ((champion->code = (unsigned char *)malloc(champion->header.prog_size))
			== NULL)
		return (-1);
	if (read(fd, champion->code, champion->header.prog_size) <
			champion->header.prog_size)
	{
		free(champion->code);
		return (-1);
	}
	return (0);
}
