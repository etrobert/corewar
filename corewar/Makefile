NAME		=	corewar

COLOR		=	\033[32m
COLOR_RESET	=	\033[0m

SRCDIR		=	srcs
INCDIR		=	includes

SRCNAM		=	main.c \
				champion_new.c champion_delete.c \
				champion_init.c champion_clear.c \
				champion_get_id.c champion_get_period_lives.c \
				process_new.c process_init.c process_cpy.c process_delete.c \
				process_get_reg.c process_set_reg.c process_valid_reg.c \
				process_get_proc_id.c process_set_proc_id.c \
				process_get_pc.c visu_init.c visu_end.c \
				print_corewar.c play_corewar.c play_events.c\
				print_process_fd.c print_champion.c print_args_parser.c \
				corewar_new.c corewar_init.c corewar_delete.c \
				corewar_advance.c corewar_end.c corewar_set_fd.c \
				corewar_set_verbosity.c corewar_set_print_aff.c \
				corewar_get_byte.c corewar_get_byte_id.c \
				corewar_get_byte_champ.c \
				corewar_get_cycle.c corewar_get_cycles_to_die.c \
				corewar_get_process_nb.c \
				corewar_id_champ.c \
				corewar_write.c corewar_read.c \
				corewar_parse_params.c corewar_extract_param.c \
				corewar_update_process.c corewar_fork.c \
				corewar_update_process_pc.c corewar_check.c \
				corewar_kill_process.c corewar_add_process.c \
				corewar_print_log.c corewar_vprint_log.c \
				corewar_print_op.c corewar_print_live.c corewar_print_cycle.c \
				corewar_print_cycles_to_die.c corewar_print_death.c \
				corewar_print_aff.c \
				apply_live.c apply_ld.c apply_st.c apply_add.c apply_sub.c \
				apply_and.c \
				apply_or.c apply_xor.c \
				apply_zjmp.c apply_sti.c apply_fork.c apply_lld.c \
				apply_aff.c apply_nothing.c apply_ldi.c apply_lldi.c \
				apply_lfork.c \
				ocp_get_type.c \
				parse_options.c open_champ_file.c parser_new.c parse_args.c \
				parser_delete.c print_help.c \
				ft_strnbrless.c ft_strnbrlesseq.c \
				print_log.c corewar_dump.c

INCNAM		=	process.h corewar.h champion.h print.h args_parser.h

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -I$(INCDIR) -I $(LIBFTDIR)/includes -I ../op/
LDFLAGS		=	-L $(LIBFTDIR) -l$(LIBFTNAM:lib%.a=%) -lncurses

GIT			=	Makefile

LIBFTDIR	=	~/work/libft
LIBFTNAM	=	libft.a

SRC			=	$(SRCNAM:%=$(SRCDIR)/%) ../op/op.c ../op/get_op_by_name.c \
				../op/get_op_by_code.c
INC			=	$(INCNAM:%=$(INCDIR)/%)
OBJ			=	$(SRC:%.c=%.o)

all:
	@$(MAKE) -C $(LIBFTDIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) printname
	@printf "%-15s%s\n" Linking $@
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(INC)
	@$(MAKE) printname
	@printf "%-15s%s\n" Compiling $@ 
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re printname

git:
	@$(MAKE) printname
	@echo Adding files to git repository
	git add $(SRC) $(INC) $(GIT)

no:
	@$(MAKE) printname
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)| grep -B1 Error | cat

printf:
	@$(MAKE) printname
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

printname:
	@printf "$(COLOR)"
	@printf "[%-15s " "$(NAME)]"
	@printf "$(COLOR_RESET)"

clean:
	@$(MAKE) printname
	@echo Suppressing obj files
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) printname
	@echo Suppressing $(NAME)
	@rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	@$(MAKE) all
