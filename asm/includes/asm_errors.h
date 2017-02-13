/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:46:46 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/12 20:27:26 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERRORS_H
# define ASM_ERRORS_H

# include "libft.h"

int		asm_usage(int ac, char **av);
int		asm_error_open(char *filename);
int		asm_error_create(char *filename);

#endif
