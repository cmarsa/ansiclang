CC = gcc
CFLAGS = -Wall -g
DEPS = get_line.h atof.h main.h
OBJ = main.c get_line.c atof.c

prog.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
run:
	./prog.out
clean:
	rm prog.out