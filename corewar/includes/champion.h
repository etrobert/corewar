/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:16:13 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/14 20:59:26 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMPION_H
# define CHAMPION_H

# include "libft.h"
# include "op.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

//TODO Choose type
typedef unsigned int	t_id_type;

typedef struct			s_champion
{
	t_header			header;
	t_id_type			id;
	unsigned char		*code;
}						t_champion;

t_champion				*champion_new(void);
int						champion_init(t_champion *champ, t_id_type id, int fd);
void					champion_delete(t_champion *champ);

#endif
