// main.c
#include "syscall.h"
#include <stdio.h>

#define BUFSIZE 1024
#undef getchar

/**
 * getchar: simple buffered version
 */
int getchar(void) {
    static char buf[BUFSIZE];
    static char *bufp= buf;
    static int n = 0;

    if (n == 0) {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n > 0) ? (unsigned char) * bufp++ : EOF;
}