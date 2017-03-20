/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:16:13 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/20 16:50:21 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMPION_H
# define CHAMPION_H

# include "libft.h"
# include "op.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef int				t_id_type;

typedef struct			s_champion
{
	t_header			header;
	t_id_type			id;
	t_id_type			intern_id;
	unsigned char		*code;
	int					color;

	unsigned int		period_lives;
}						t_champion;

t_champion				*champion_new(void);
void					champion_delete(t_champion *champ);

int						champion_init(t_champion *champ, t_id_type id, int fd);
void					champion_clear(t_champion *champion);

t_id_type				champion_get_id(t_champion *champion);
unsigned int			champion_get_period_lives(t_champion *champ);

#endif
