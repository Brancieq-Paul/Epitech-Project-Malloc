##
## EPITECH PROJECT, 2021
## B-PSU-400-RUN-4-1-malloc-paul.brancieq
## File description:
## Makefile
##

EXEC = libmy_malloc.so
SOURCES =	$(wildcard *.c)

DEBUG = -g -ggdb -g3

all:
	gcc -shared -o $(EXEC) -fPIC $(SOURCES) -fcommon

re:
	make fclean
	gcc -shared -o $(EXEC) -fPIC $(SOURCES) -fcommon

libdebug:
	make fclean
	gcc -shared -o $(EXEC) -fPIC $(SOURCES) -fcommon $(DEBUG)

tests_run:
	make libdebug
	gcc -o test tests/*.c tests/tests_files/*.c *.c $(DEBUG) --coverage
	./test
	gcovr

tests_real:
	make libdebug
	gcc -o test tests/*.c tests/tests_files/*.c -L./ -lmy_malloc $(DEBUG)
	LD_LIBRARY_PATH=./ ./test
	make libdebug
	make -sC tests/ls/
	make libdebug
	LD_PRELOAD=./libmy_malloc.so ls


clean:
	rm -rf *.o

fclean: clean
	rm -rf $(EXEC)
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf vgcore.*
	rm -f test
	make -sC ./tests/ls/ fclean