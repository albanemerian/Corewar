##
## EPITECH PROJECT, 2023
## my_organize
## File description:
## my_organize
##

CC	=	gcc

NAME	=	corewar

UNIT_TEST	= test

CFLAGS	=	-Wshadow -Werror -Wall -I./include

CRITFLAG	=	tests/test_lib.c tests/test_orga.c --coverage -lcriterion

LIBS	=	-L./ -lmy -L./ -lprintf

TEST_LIBS	=	-L./ -lmy

SRC		=   main.c						\
			src/analize_param.c			\
			src/helper.c				\
			src/handle_file.c			\
			src/free_func.c				\
			src/init_struct.c 			\
			src/flag_handler.c			\
			src/get_dump.c				\
			src/get_adresses.c			\
			src/get_prog_number.c		\
			src/init_players.c			\
			src/init_arena.c			\
			src/execute_commands.c		\
			src/instructions/add.c 		\
			src/instructions/aff.c 		\
			src/instructions/and.c 		\
			src/instructions/fork.c 	\
			src/instructions/ld.c 		\
			src/instructions/ldi.c 		\
			src/instructions/lfork.c 	\
			src/instructions/live.c 	\
			src/instructions/lld.c 		\
			src/instructions/lldi.c 	\
			src/instructions/or.c 		\
			src/instructions/st.c 		\
			src/instructions/sti.c 		\
			src/instructions/sub.c 		\
			src/instructions/xor.c 		\
			src/instructions/zjmp.c		\
			src/instructions/hex_byte.c	\
			src/check_memory_space.c	\
			src/print_arena.c			\
			src/end_condition.c

SRCTEST	=

OBJ		=	$(SRC:.c=.o)

all:	printf libmy $(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"

$(UNIT_TEST): libmy
			$(CC) -o $(UNIT_TEST) $(SRCTEST) $(CRITFLAG) $(TEST_LIBS)

tests_run:	$(UNIT_TEST)
			@./$(UNIT_TEST)
			@gcovr --exclude tests/

.PHONY: libmy printf

printf:
	$(MAKE) -C lib/printf

libmy:
	$(MAKE) -C lib/my


norm:
	@make clean
	@make fclean
	@coding-style . .
	@cat coding-style-reports.log

clean:
			$(MAKE) -C lib/my clean
			$(MAKE) -C lib/printf clean
			@rm -f $(OBJ)
			@rm -f *.gc*
			@rm -f coding-style-reports.log
			@rm -f *~
			@rm -f *.gcda
			@rm -f *.gcno
			@rm -f libmy.a
			@rm -f libprintf.a

fclean:	clean
			$(MAKE) -C lib/my fclean
			$(MAKE) -C lib/printf fclean
			@rm -f $(NAME)
			@rm -f $(UNIT_TEST)
			@echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"
			@rm -f libmy.a

re:	fclean all
