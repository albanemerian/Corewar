##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC	=	my_printf.c								\
		pf_base_conversion.c 					\
		pf_floating_nbr.c 						\
		pf_exposant_nbr.c 						\
		pf_mini_printf.c							\
		space_flags.c 							\
		fill_functions.c 						\
		hashtag_flag.c 							\
		zero_flags.c 							\
		my_find_prime_sup.c						\
		my_float_len.c 							\
		my_getnbr.c								\
		my_intlen.c 								\
		my_isneg.c								\
		my_itoa.c								\
		my_longlen.c 							\
		my_put_exp.c								\
		my_put_exp2.c							\
		my_put_float.c							\
		my_put_g.c 								\
		my_is_prime.c							\
		my_putchar.c								\
		my_put_long.c							\
		my_put_llong.c 							\
		my_put_nbr.c								\
		my_put_unsigned.c 						\
		my_putstr.c								\
		my_revstr.c								\
		my_show_word_array.c						\
		my_sort_int_array.c						\
		my_strcapitalize.c						\
		my_strcat.c								\
		my_strcmp.c								\
		my_strcpy.c								\
		my_strdup.c								\
		my_str_isalpha.c							\
		my_str_islower.c							\
		my_str_isnum.c							\
		my_str_isprintable.c						\
		my_str_isupper.c							\
		my_strlen.c								\
		my_strlowcase.c							\
		my_strncat.c								\
		my_strncmp.c								\
		my_strncpy.c								\
		my_strstr.c								\
		my_str_to_word_array.c					\
		my_strupcase.c							\
		my_swap.c								\
		my_unsignedlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libprintf.a

all:	$(NAME)

$(NAME): $(OBJ)
	@cp printf.h ../../include/
	@cp struct.h ../../include/
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../../

clean:
	@rm -f  *.o
	@rm -f *.gc*

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TESTER)

re:	fclean all
