CC=gcc
CFLAGS=-Wall -Wextra -std=c99

todo: todo.o
	$(CC) $(CFLAGS) -o todo todo.o

todo.o: todo.c todo.h
	$(CC) $(CFLAGS) -c todo.c

clean:
	rm -f todo todo.o
	rm a.out
	rm users.dat