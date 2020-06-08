CC = gcc
CFLAGS = -Wall -g
DEPS = expr.h
OBJ = main.c stack.c

expr.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
run:
	./expr.out 2.221 3.2 5.8 p -
clean:
	rm expr.out