NAME		=	asm

SRCDIR		=	srcs
INCDIR		=	includes
OPDIR		=	../op

SRCNAM		=	asm_main.c asm_usage.c asm_open.c asm_create.c	\
				asm_get_size.c asm_save_file.c asm_get_prog_name.c	\
				asm_get_prog_comment.c asm_get_params.c	\
				asm_get_line_size.c asm_get_params_size.c asm_get_bytes.c	\
				asm_get_pos.c asm_param_byte_label_dir.c	\
				asm_param_byte_label_ind.c asm_free_split.c	\
				asm_write_bytes.c
INCNAM		=	asm.h

CC			=	clang
CFLAGS		=	-g -Wall -Wextra -Werror -I $(INCDIR) -I $(LIBFTDIR)/includes \
				-I $(OPDIR)
LDFLAGS		=	-L $(LIBFTDIR) -l$(LIBFTNAM:lib%.a=%)

GIT			=	Makefile

LIBFTDIR	=	~/work/libft
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
	@printf "Linking\t\t%s\n" $@
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(INC)
	@$(MAKE) printname
	@printf "Compiling\t%s\n"	$@
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
	@printf "[%-20s " "$(NAME)]"

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
