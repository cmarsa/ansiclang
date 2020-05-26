// longestline_extern.c
/*
    Because automatic variables come and go with function invocation, they do not retain their
    values from one call to the next, and must be explicitly set upon each entry. If they are not set,
    they will contain garbage.

    As an alternative to automatic variables, it is possible to define variables that are external to
    all functions, that is, variables that can be accessed by name by any function. (This
    mechanism is rather like Fortran COMMON or Pascal variables declared in the outermost
    block.) Because external variables are globally accessible, they can be used instead of
    argument lists to communicate data between functions. Furthermore, because external
    variables remain in existence permanently, rather than appearing and disappearing as
    functions are called and exited, they retain their values even after the functions that set them
    have returned.
*/
#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

/* main: print longest input line; specialzied version */
int main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}


/* get_line: specialized version */
int get_line(void) {
    int c, i;
    extern char line[];
    
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}


/* copy: specialized version */
void copy(void) {
    int i;
    extern char line[], longest[];

    i = 0;
    while((longest[i] = line[i]) != '\0')
        i++;
}