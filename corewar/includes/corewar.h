/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:03:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/07 17:33:17 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "champion.h"
# include "process.h"

typedef struct		s_corewar
{
	t_cbuff			*memory;
	t_cbuff			*memory_id;
	t_list			*process;
	t_cycle_type	cycle;
	t_cycle_type	last_check;
	t_cycle_type	cycles_to_die;
	t_cycle_type	clear_checks;
	unsigned int	nbr_live;
	t_id_type		last_living_champ;
	int				fd;
}					t_corewar;

typedef union		u_param
{
	unsigned char	c;
	unsigned short	s;
	unsigned int	i;
}					t_param;

typedef struct		s_op_params
{
	t_param			params[4];
	unsigned int	offset;
	unsigned char	ocp;
}					t_op_params;

typedef int			(*t_f_cw_op)(t_corewar *, t_process *);

/*
** public: =====================================================================
*/

t_corewar			*corewar_new(const t_list *champions, int fd);
int					corewar_init(t_corewar *corewar, const t_list *champions,
		int fd);
void				corewar_delete(t_corewar *corewar);

int					corewar_advance(t_corewar *corewar);
bool				corewar_end(const t_corewar *corewar);

void				corewar_set_fd(t_corewar *corewar, int fd);
unsigned char		corewar_get_byte(const t_corewar *corewar,
		unsigned int pos);
t_id_type			corewar_get_byte_id(t_corewar *corewar, unsigned int pos);

/*
** private: ====================================================================
*/

/*
** corewar_parse_params checks if the register given is not correct
** pour cette fonction tester les reactions quand le code est 00
*/

void				corewar_write(t_corewar *corewar, t_memory mem, size_t pos,
		t_id_type id);
int					corewar_parse_params(t_corewar *corewar, t_process *process,
		t_op_params *params);
unsigned int		corewar_extract_param(const t_corewar *corewar,
		const t_process *process, const t_op_params *params, unsigned char id);

void				corewar_update_process_pc(t_corewar *corewar,
		t_process *proc, int value);

void				corewar_check(t_corewar *corewar);
/*
** Reads the op pointed to by process->pc, saves it and
** sets process wait time accordingly
*/
void				corewar_update_process(t_corewar *corewar,
		t_process *process);

int					corewar_add_process(t_corewar *corewar, t_process *process);
int					corewar_fork(t_corewar *corewar,
		t_process *parent, t_reg_type pc);
void				corewar_kill_process(t_corewar *corewar);

/*
** op functions ================================================================
*/

char				ocp_get_type(unsigned char ocp, int id);

int					apply_nothing(t_corewar *corewar, t_process *process);
int					apply_live(t_corewar *corewar, t_process *process);
int					apply_ld(t_corewar *corewar, t_process *process);
int					apply_st(t_corewar *corewar, t_process *process);
int					apply_and(t_corewar *corewar, t_process *process);
int					apply_or(t_corewar *corewar, t_process *process);
int					apply_xor(t_corewar *corewar, t_process *process);
int					apply_zjmp(t_corewar *corewar, t_process *process);
int					apply_fork(t_corewar *corewar, t_process *process);
int					apply_aff(t_corewar *corewar, t_process *process);

#endif
