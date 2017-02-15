/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:16:13 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/11 18:52:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMPION_H
# define CHAMPION_H

typedef struct		s_champion
{
	//TYpe ?
	size_t			id;
	char			*name;
	char			*comment;
	char			*code;
}					t_champion;

#endif