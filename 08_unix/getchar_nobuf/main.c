#include "syscall.h"

/**
 * getchar: unbuffered single character inpu
 */
int getchar(void) {
    char c;
    return (read(0, &c, 1) == 1) ? (unsigned char) c: EOF;
}