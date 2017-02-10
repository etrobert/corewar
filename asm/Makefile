NAME		=	exec

SRCDIR		=	.
OBJDIR		=	objs
INCDIR		=	includes

SRCNAM		=	
INCNAM		=

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -I$(INCDIR) -I $(LIBFTDIR)/includes
LDFLAGS		=	-L $(LIBFTDIR) -l$(LIBFTNAM:lib%.a=%)

GIT			=	Makefile

LIBFTDIR	=	~/work/libft
LIBFTNAM	=	libft.a

SRC			=	$(SRCNAM:%=$(SRCDIR)/%)
INC			=	$(INCNAM:%=$(INCDIR)/%)
OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all:

$(NAME): $(OBJ)
	@printf "Linking\t\t%s\n" $@
	@$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@printf "Compiling\t%s\n"	$@
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re

git:
	@echo Adding files to git repository
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)| grep -B1 Error | cat

printf:
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

clean:
	@echo Suppressing obj files
	@rm -rf $(OBJDIR)

fclean: clean
	@echo Suppressing $(NAME)
	@rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	@$(MAKE) all
