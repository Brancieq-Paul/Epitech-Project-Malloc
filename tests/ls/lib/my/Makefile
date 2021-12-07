##
## EPITECH PROJECT, 2019
## makefile
## File description:
## 11
##

SRC		=	my_compute_power_rec.c	\
			my_compute_square_root.c	\
			my_getnbr.c	\
			my_isneg.c	\
			my_putchar.c	\
			my_put_nbr.c	\
			my_putstr.c	\
			my_revstr.c	\
			my_sort_int_array.c	\
			my_strcpy.c	\
			my_strdup.c	\
			my_str_isalphanum.c	\
			my_strlen.c	\
			my_strncpy.c	\
			my_strstr.c	\
			my_swap.c	\
			my_isnum.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	compil
	make fclean

compil:		$(OBJ)
	ar rc $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)

clean:
		rm -f *.o
		rm -f tests/*.o
		rm -f *.gc*