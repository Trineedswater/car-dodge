CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o animate.o collision.o game.o linkedList.o map.o save.o structs.o terminal.o userInput.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c game.h
	$(CC) $(CFLAGS) main.c -c

game.o : game.c game.h structs.h map.h userInput.h linkedList.h save.h collision.h animate.h
	$(CC) $(CFLAGS) game.c -c

animate.o : animate.c animate.h structs.h
	$(CC) $(CFLAGS) animate.c -c

userInput.o : userInput.c userInput.h terminal.h collision.h structs.h
	$(CC) $(CFLAGS) userInput.c -c

map.o : map.c map.h structs.h
	$(CC) $(CFLAGS) map.c -c

collision.o : collision.c collision.h structs.h
	$(CC) $(CFLAGS) collision.c -c

random.o : random.c random.h
	$(CC) $(CFLAGS) random.c -c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

clean :
	rm -f $(EXEC) $(OBJ)
