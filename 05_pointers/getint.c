// getint.c
#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'  // signal that a number was found
#define BUFSIZE 100

// global vars
char buf[BUFSIZE];
int bufp = 0;

// function prototypes
int getch(void);
void ungetch(int);
int getint(int *pn);


/**
 * getint: get next integer from input to *pn
 */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    
    return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp]: getchar();
}


void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}