# Определяем компилятор и флаги компиляции
CC=clang
CFLAGS=-Wall -Wextra -std=c99

# Цель: todo
todo: todo.o
	$(CC) $(CFLAGS) -o todo todo.o

# Зависимости todo.o
todo.o: todo.c todo.h
	$(CC) $(CFLAGS) -c todo.c

# Цель: очистка
clean:
	rm -f todo todo.o
