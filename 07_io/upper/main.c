// main.c
#include <stdio.h>
#include <ctype.h>

/**
 * upper: convert input to upper case
 */
int main() {
    int c;
    while ((c = getchar()) != EOF)
        putchar(toupper(c));
    return 0;
}