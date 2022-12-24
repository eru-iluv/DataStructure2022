
# -*-Makefile-*-

UTIL = utils/utils.c malha_logistica/malha_logistica.c grafo/grafo.c
MAIN = main.c
BINARY = executavel

all:
		gcc -std=c99 -Wall -g $(UTIL) $(MAIN) -o $(BINARY) -lm
run:
		./$(BINARY)
debug:
		gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
		valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
		@rm *.o
