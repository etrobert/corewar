NAME		=	asm

COLOR		=	\033[33m
COLOR_RESET	=	\033[0m

SRCDIR		=	srcs
INCDIR		=	includes
OPDIR		=	../op

SRCNAM		=	asm_main.c asm_usage.c asm_open.c asm_create.c	\
				asm_get_size.c asm_save_file.c asm_get_prog_name.c	\
				asm_get_prog_comment.c asm_get_params.c	\
				asm_get_line_size.c asm_get_params_size.c	\
				asm_check_separators.c asm_get_bytes.c	\
				asm_get_pos.c asm_param_byte_label_dir.c	\
				asm_param_byte_label_ind.c asm_free_split.c	\
				asm_complete_ocp.c asm_go_to_instruct.c	\
				asm_write_bytes.c asm_free_asm.c asm_free_file.c \
				asm_check_max_params.c asm_add_ocp.c asm_get_label.c \
				asm_go_to_instruct_size.c asm_check_prog_name.c \
				asm_check_prog_comment.c
INCNAM		=	asm.h

CC			=	clang
CFLAGS		=	-g -Wall -Wextra -Werror -I $(INCDIR) -I $(LIBFTDIR)/includes \
				-I $(OPDIR)
LDFLAGS		=	-L $(LIBFTDIR) -l$(LIBFTNAM:lib%.a=%)

GIT			=	Makefile

LIBFTDIR	=	../libft
LIBFTNAM	=	libft.a

SRC			=	$(SRCNAM:%=$(SRCDIR)/%)	\
				../op/op.c				\
				../op/get_op_by_code.c	\
				../op/get_op_by_name.c
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
