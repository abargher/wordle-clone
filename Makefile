.PHONY: clean

CC = gcc
CFLAGS = -o

all: wordle

wordle: main.c wordle.c
	$(CC) $(CFLAGS) wordle main.c wordle.c

clean:
	rm -f wordle *.o a.out