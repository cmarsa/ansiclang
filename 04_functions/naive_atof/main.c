// main.c
#include <stdio.h>
#include "main.h"
#define MAXLINE 100

/**
 * rudimentary calculator
 */
int main() {
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);

    printf("Rudimentary calculator.\nSums input floats:\n");
    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    
    return 0;
}