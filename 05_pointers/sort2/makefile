CC = gcc
CFLAGS = -Wall -g
DEPS = 
OBJ = sort2.c

prog.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
run:
	./prog.out -n -r
clean:
	rm prog.out