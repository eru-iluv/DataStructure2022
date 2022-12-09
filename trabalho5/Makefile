
# -*-Makefile-*-

UTIL = utils.c nodes.c big_numbers.c binary_tree.c cliente.c
MAIN = main.c
BINARY = executavel

all:
		gcc -std=c99 -Wall -g $(UTIL) $(MAIN) -o $(BINARY)
run:
		./$(BINARY)
debug:
		gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
		valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
		@rm *.o
