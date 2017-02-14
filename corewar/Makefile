NAME		=	corewar

SRCDIR		=	srcs
OBJDIR		=	objs
INCDIR		=	includes

SRCNAM		=	main.c champion_new.c champion_init.c champion_delete.c
INCNAM		=	process.h corewar.h champion.h

CC			=	clang
CFLAGS		=	-Wall -Wextra -I$(INCDIR) -I $(LIBFTDIR)/includes -I ../op/
LDFLAGS		=	-L $(LIBFTDIR) -l$(LIBFTNAM:lib%.a=%)

GIT			=	Makefile

LIBFTDIR	=	~/work/libft
LIBFTNAM	=	libft.a

SRC			=	$(SRCNAM:%=$(SRCDIR)/%)
INC			=	$(INCNAM:%=$(INCDIR)/%)
OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all:
	@$(MAKE) -C $(LIBFTDIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) printname
	@printf "Linking\t\t%s\n" $@
	@$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@$(MAKE) printname
	@printf "Compiling\t%s\n"	$@
	@mkdir -p $(OBJDIR)
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
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) printname
	@echo Suppressing $(NAME)
	@rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	@$(MAKE) all
