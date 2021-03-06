/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <etrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:03:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/22 14:20:17 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define CW_VB_LIVE			1
# define CW_VB_CYCLES		2
# define CW_VB_OP			4
# define CW_VB_DEATHS		8
# define CW_VB_PC_MOV 		16
# define CW_VB_PRE_CYCLES	32
# define CW_VB_OP_PC		64

# define CW_VB_MAX			64
# define CW_VB_MAX_ADD		((CW_VB_MAX * 2) - 1)
# define CW_VB_INIT			0

# include <stdarg.h>
# include "champion.h"
# include "process.h"

typedef struct		s_corewar
{
	t_cbuff			*memory;
	t_cbuff			*memory_id;

	t_list			*process;
	unsigned int	last_proc_id;

	t_cycle_type	cycle;
	t_cycle_type	last_check;
	t_cycle_type	cycles_to_die;
	t_cycle_type	clear_checks;

	unsigned int	nbr_live;
	t_champion		*last_living_champ;

	int				fd;
	int				verbosity;
	bool			print_aff;

	t_list			*champions;
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

t_corewar			*corewar_new(t_list *champions, int fd);
int					corewar_init(t_corewar *corewar, t_list *champions,
		int fd);
void				corewar_delete(t_corewar *corewar);

int					corewar_advance(t_corewar *corewar);
bool				corewar_end(const t_corewar *corewar);

void				corewar_set_fd(t_corewar *corewar, int fd);
void				corewar_set_verbosity(t_corewar *corewar, int verbosity);
void				corewar_set_print_aff(t_corewar *corewar, bool print_aff);

unsigned char		corewar_get_byte(const t_corewar *corewar,
		unsigned int pos);

t_champion			*corewar_get_byte_champ(t_corewar *corewar,
		unsigned int pos);
t_id_type			corewar_get_byte_id(t_corewar *corewar, unsigned int pos);
t_cycle_type		corewar_get_cycle(t_corewar *corewar);
t_cycle_type		corewar_get_cycles_to_die(t_corewar *corewar);
t_champion			*corewar_get_winner(t_corewar *corewar);
t_size_type			corewar_get_process_nb(t_corewar *corewar);

/*
** private: ====================================================================
*/

t_champion			*corewar_id_champ(const t_corewar *corewar, t_id_type id);

/*
** corewar_parse_params checks if the register given is not correct
** pour cette fonction tester les reactions quand le code est 00
*/

void				corewar_write(t_corewar *corewar, t_memory mem, size_t pos,
		t_id_type id);
void				corewar_read(const t_corewar *corewar,
		t_memory mem, size_t pos);
int					corewar_parse_params(const t_corewar *corewar,
		const t_process *process, t_op_params *params);
unsigned int		corewar_extract_param(const t_corewar *corewar,
		const t_process *process, const t_op_params *params, unsigned char id);

void				corewar_update_process_pc(const t_corewar *corewar,
		t_process *proc, int value);

void				corewar_check(t_corewar *corewar);

/*
** Reads the op pointed to by process->pc, saves it and
** sets process wait time accordingly
*/
void				corewar_update_process(const t_corewar *corewar,
		t_process *process);

int					corewar_add_process(t_corewar *corewar, t_process *process);
int					corewar_fork(t_corewar *corewar,
		t_process *parent, t_reg_type pc);
void				corewar_kill_process(t_corewar *corewar);

/*
** print functions =============================================================
**
** The internal print functions return the number of characters printed
** or a negative value in case of failure
*/

int					corewar_print_op(const t_corewar *corewar,
		const t_process *process, char *fmt, ...);
int					corewar_print_log(const t_corewar *corewar, char *fmt, ...);
int					corewar_vprint_log(const t_corewar *corewar, char *fmt,
		va_list ap);
int					corewar_print_live(const t_corewar *corewar,
		unsigned int id);
int					corewar_print_cycle(const t_corewar *corewar);
int					corewar_print_cycles_to_die(const t_corewar *corewar);
int					corewar_print_death(const t_corewar *corewar,
		const t_process *process);
int					corewar_print_aff(const t_corewar *corewar, int val);

/*
** op functions ================================================================
*/

char				ocp_get_type(unsigned char ocp, int id);

int					apply_nothing(t_corewar *corewar, t_process *process);
int					apply_live(t_corewar *corewar, t_process *process);
int					apply_ld(t_corewar *corewar, t_process *process);
int					apply_st(t_corewar *corewar, t_process *process);
int					apply_add(t_corewar *corewar, t_process *process);
int					apply_sub(t_corewar *corewar, t_process *process);
int					apply_and(t_corewar *corewar, t_process *process);
int					apply_or(t_corewar *corewar, t_process *process);
int					apply_xor(t_corewar *corewar, t_process *process);
int					apply_zjmp(t_corewar *corewar, t_process *process);
int					apply_ldi(t_corewar *corewar, t_process *process);
int					apply_sti(t_corewar *corewar, t_process *process);
int					apply_fork(t_corewar *corewar, t_process *process);
int					apply_lld(t_corewar *corewar, t_process *process);
int					apply_lldi(t_corewar *corewar, t_process *process);
int					apply_lfork(t_corewar *corewar, t_process *process);
int					apply_aff(t_corewar *corewar, t_process *process);

#endif
