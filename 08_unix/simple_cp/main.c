#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include "syscall.h"

#define PERMS 0666
#define BUFSIZE 1024

// function prototypes
void error(char *, ...);

/**
 * cp:
 * copy f1 to f2
 */
int main(int argc, char *argv[]) {
    int f1, f2, n;
    char buf[BUFSIZE];

    if(argc != 3)
        error("Usage: cp from to");
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
        error("cp: can't open %s", argv[1]);
    if ((f2 = creat(argv[2], PERMS)) == -1)
        error("cp: can't create %s, mode %03o", argv[2], PERMS);
    
    while ((n = read(f1, buf, BUFSIZE)) > 0)
        if (write(f2, buf, n) != n)
            error("cp: write error on file %s", argv[2]);
    return 0;
}

/**
 * error:
 * print an error message and die
 */
void error(char *fmt, ...) {
    va_list args;
    
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}


/*
    There is a limit (often about 20) on the number of files that a program may open
    simultaneously. Accordingly, any program that intends to process many files must be
    prepared to re-use file descriptors. The function close(int fd) breaks the connection
    between a file descriptor and an open file, and frees the file descriptor for use with some other
    file; it corresponds to fclose in the standard library except that there is no buffer to flush.
    Termination of a program via exit or return from the main program closes all open files
*/
