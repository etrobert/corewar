/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:50:20 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/25 21:08:09 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "champion.h"
#include "corewar.h"
#include "print.h"

void	print_bytes(int x)
{
	unsigned int		i;

	i = 0;
	while (i < sizeof(x))
	{
		ft_printf("%#.2x\n", ((unsigned char *)(&x))[i]);
		++i;
	}
}

void	print_champion(t_champion *champion)
{
	ft_printf("Here's our hero :\n");
	ft_printf("His name is %s.\n", champion->header.prog_name);
	ft_printf("And here is his story : %s\n", champion->header.comment);
	ft_printf("Lets not forget his weight : %u\n", champion->header.prog_size);
	ft_printf("And that he is before all a magician : %x\n", champion->header.magic);
	ft_printf("And finally the code :\n");
	for (unsigned int i = 0; i < champion->header.prog_size ; ++i)
	{
		ft_printf("%.2#x ", champion->code[i]);
	}
	ft_printf("\n");
}

static bool	int_good_size(void)
{
	return (sizeof(unsigned int) == 4);
}

static void	print_init_sdl(t_visu *visu)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	visu->screen = SDL_SetVideoMode(2560, 1440, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Corewar", NULL);
	if ((visu->font = TTF_OpenFont("monaco.ttf", 12)) == NULL)
		ft_printf("font = null");
	visu->white.r = 255;
	visu->white.g = 255;
	visu->white.b = 255;
	visu->black.r = 0;
	visu->black.g = 0;
	visu->black.b = 0;
	visu->text = TTF_RenderText_Blended(visu->font, "Salut", visu->white);
}

int	play_corewar(t_corewar *corewar)
{
	int				ret;
	t_visu			visu;
	SDL_Event		event;

	if (corewar == NULL)
		return (0);
	print_init_sdl(&visu);
	while (!corewar_end(corewar))
	{
		SDL_FillRect(visu.screen, NULL, SDL_MapRGB(visu.screen->format, 30, 30, 30));
		print_corewar(corewar, &visu);
//		visu.pos.x = 50;
//		visu.pos.y = 50;
//		SDL_BlitSurface(visu.text, NULL, visu.screen, &(visu.pos));
		SDL_Flip(visu.screen);
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
		{
			SDL_Quit();
			return (0);
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				SDL_Quit();
				return (0);
			}
		}
		if ((ret = corewar_advance(corewar)) < 0)
		{
			TTF_CloseFont(visu.font);
			TTF_Quit();
			SDL_Quit();
			return (ret);
		}
//		usleep(100000);
	}
	TTF_CloseFont(visu.font);
	TTF_Quit();
	SDL_Quit();
	return (0);
}

int main(int argc, char **argv)
{
	t_champion	*champ;
	t_list		*list;
	t_corewar	*cw;

	(void)argc;
	(void)argv;

	if (!int_good_size())
	{
		ft_dprintf(2, "This system is not supported.\n");
		return (0);
	}
	if ((champ = champion_new()) == NULL)
	{
		ft_dprintf(2, "ERROR CREATING CHAMPION\n");
		return (-1);
	}
	if (champion_init(champ, 0, 0) < 0)
	{
		ft_dprintf(2, "ERROR LOADING FILE\n");
		champion_delete(champ);
		return (-1);
	}
	list = ft_list_new();
	ft_list_push_back(list, champ);
	cw = corewar_new(list);

	play_corewar(cw);

	corewar_delete(cw);
	champion_delete(champ);
	return (0);
}
