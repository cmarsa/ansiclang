CC = gcc
CFLAGS = -Wall -g
DEPS = getop.h stack.h
OBJ = main.c getop.c stack.c

prog.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
run:
	./prog.out
clean:
	rm prog.out