/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 07:15:59 by tbeldame          #+#    #+#             */
/*   Updated: 2017/03/17 16:48:55 by tbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"

int	parse_args(t_parser *parser, t_list **champs)
{
	while (parser->cur_arg < parser->ac)
	{
		if (parser->av[parser->cur_arg][0] == '-')
		{
			if (parse_options(parser, champs) < 0)
				return (-1);
		}
		else if (open_champ_file(parser, 0, false, champs) < 0)
		{
			ft_dprintf(2, "Invalid champion file\n");
			return (-1);
		}
		++parser->cur_arg;
	}
	return (0);
}
