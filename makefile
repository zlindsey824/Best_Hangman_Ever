CC = g++

CFLAGS = -g -Wall -o

SRC = Hangman.cpp HangmanBoard.cpp HangmanGame.cpp CP.cpp
OBJ = Hangman.o HangmanBoard.o HangmanGame.o CP.o
PROG = hangman

$(PROG) : $(OBJ)

$(OBJ) : $(SRC)

compile:
	$(CC) $(SRC) $(CFLAGS) $(PROG)

run:
	./$(PROG)

clean:
	rm *.o $(PROG)
