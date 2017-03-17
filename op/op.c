/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/03/14 19:01:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", false, false, false},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", true, false, false},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", true, false, false},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", true, false, false},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", true, false, false},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", true, false, false},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", true, false, false},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", true, false, false},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", false, true, false},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", true, true, true},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", true, true, false},
	{"fork", 1, {T_DIR}, 12, 800, "fork", false, true, false},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", true, false, true},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", true, true, true},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", false, true, true},
	{"aff", 1, {T_REG}, 16, 2, "aff", true, false, false},
	{NULL, 0, {0}, 0, 0, NULL, false, false, false}
};
