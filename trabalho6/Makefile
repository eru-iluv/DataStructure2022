
# -*-Makefile-*-

UTIL = utils/utils.c arvoreAVL/avl.c jogos/jogo.c
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
