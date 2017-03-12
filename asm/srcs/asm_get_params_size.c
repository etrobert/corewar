/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_params_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:16:48 by mverdier          #+#    #+#             */
/*   Updated: 2017/03/12 16:43:39 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_reg_size(char *param, t_op *op_tab, int i, unsigned int *size)
{
	int		reg;

	reg = 0;
	if (param[0] == 'r')
	{
		reg = ft_atoi(param + 1);
		if (!(op_tab->params[i] & T_REG))
		{
			ft_dprintf(2, "Bad param \'%s\' for \'%s\'\n", param,
					op_tab->name);
			return (0);
		}
		if (reg < 0 || reg > REG_NUMBER)
		{
			ft_dprintf(2, "Bad reg number \'%d\' for \'%s\'\n", reg,
					op_tab->name);
			return (0);
		}
		(*size) += 1;
	}
	return (1);
}

static int	asm_dir_size(char *param, t_op *op_tab, int i, unsigned int *size)
{
	if (param[0] == DIRECT_CHAR && op_tab->small_direct == true)
	{
		if (!(op_tab->params[i] & T_DIR))
		{
			ft_dprintf(2, "Bad param \'%s\' for \'%s\'\n", param,
					op_tab->name);
			return (0);
		}
		(*size) += 2;
	}
	else if (param[0] == DIRECT_CHAR)
	{
		if (!(op_tab->params[i] & T_DIR))
		{
			ft_dprintf(2, "Bad param \'%s\' for \'%s\'\n", param,
					op_tab->name);
			return (0);
		}
		(*size) += 4;
	}
	return (1);
}

static int	asm_ind_size(char *param, t_op *op_tab, int i, unsigned int *size)
{
	if (ft_str_test_chars(param, &ft_isdigit) != 0 ||
			(param[0] == '-' && ft_str_test_chars(param + 1, &ft_isdigit) != 0)
			|| (param[0] == LABEL_CHAR))
	{
		if (!(op_tab->params[i] & T_IND))
		{
			ft_dprintf(2, "Bad param \'%s\' for \'%s\'\n", param,
					op_tab->name);
			return (0);
		}
		(*size) += 2;
	}
	return (1);
}

static int	asm_params_loop(char **split, int n, t_op *op_tab,
		unsigned int *size)
{
	int		i;

	i = 0;
	while (split[n + i])
	{
		if (split[n + i][0] == COMMENT_CHAR || split[n + i][0] == ';')
		{
			if (op_tab->ocp == true)
				return (*size + 2);
			return (*size + 1);
		}
		if (!asm_check_max_params(i, op_tab, split, n) ||
				!asm_reg_size(split[n + i], op_tab, i, size) ||
				!asm_dir_size(split[n + i], op_tab, i, size) ||
				!asm_ind_size(split[n + i], op_tab, i, size))
			return (-1);
		i++;
	}
	return (0);
}

int			asm_get_params_size(char **split, int n, t_op *op_tab)
{
	unsigned int	size;
	int				ret;

	size = 0;
	if (!split[n])
	{
		ft_dprintf(2, "No params for \'%s\' (take %d)\n", op_tab->name,
				op_tab->nb_params);
		return (-1);
	}
	if ((ret = asm_params_loop(split, n, op_tab, &size)) != 0)
		return (ret);
	if (op_tab->ocp == true)
		return (size + 2);
	return (size + 1);
}
