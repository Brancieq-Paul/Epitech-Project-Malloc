##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compil prog
##

SRC	=	main.c		\
		src/charadd.c	\
		src/statis/statis.c	\
		src/no_arg.c	\
		src/list/fill_list_s.c	\
		src/list/display_list_s.c	\
		src/sort/sort_alpha.c	\
		src/path.c	\
		src/sort/sort_choice.c	\
		src/verifs_opt.c	\
		src/ls_all.c	\
		src/tabpath_to_string.c	\
		src/display_and_recursive.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

re:
	make fclean -sC .
	make -sC lib/my/
	make clean -sC lib/my/
	make compil
	make run

compil:			$(OBJ)
		gcc -o $(NAME) $(SRC) lib/my/*.c -I./include/  -L./../../ -lmy_malloc -g -g3 -ggdb

run:
	LD_LIBRARY_PATH=../../ ./my_ls

clean:
		rm -f *.o
		rm -f src/*.o
		rm -f src/statis/*.o
		rm -f src/list/*.o
		rm -f src/sort/*.o

fclean:	clean
		rm -f $(NAME)

debug:			$(OBJ)
		gcc -g -g3 -ggdb -o $(NAME) $(SRC) -I./include/ -L./lib/my/ -lmy