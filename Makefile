GIT			=	README.md Makefile \
				resources/asm resources/corewar resources/op.h resources/op.c \
				resources/resources_corewar.pdf resources/corewar.pdf \
				op/op.h op/op.c champions/mowgli.s champions/long_name.s

all: asm/asm corewar/corewar

asm/asm:
	@$(MAKE) -C asm/

corewar/corewar:
	@$(MAKE) -C corewar/

.PHONY: all git no check clean fclean re

git:
	@$(MAKE) git -C asm
	@$(MAKE) git -C corewar
	git add $(GIT)

no:
	@$(MAKE) no -C asm
	@$(MAKE) no -C corewar

check: no

clean:
	@$(MAKE) clean -C asm
	@$(MAKE) clean -C corewar

fclean:
	@$(MAKE) fclean -C asm
	@$(MAKE) fclean -C corewar

cclean:
	@printf "Suppressing all .cor files\n"
	@rm -rf *.cor
	@rm -rf */*.cor
	@rm -rf */*/*.cor
	@rm -rf */*/*/*.cor

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	@$(MAKE) all
