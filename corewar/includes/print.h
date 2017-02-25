/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:31:31 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/25 21:08:12 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "corewar.h"

# include <SDL.h>
# include <SDL_ttf.h>

# define PRINT_WIDTH	64

typedef struct			s_visu
{
	SDL_Surface			*screen;
	SDL_Surface			*text;
	TTF_Font			*font;
	SDL_Color			white;
	SDL_Color			black;
	SDL_Rect			pos;
}						t_visu;

void					print_corewar(t_corewar *cw, t_visu *visu);

#endif
