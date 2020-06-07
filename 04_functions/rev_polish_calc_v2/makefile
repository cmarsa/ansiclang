CC = gcc
CFLAGS = -Wall -g
DEPS = calc.h
OBJ = main.c getop.c stack.c getch.c

prog.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
run:
	./prog.out
clean:
	rm prog.out