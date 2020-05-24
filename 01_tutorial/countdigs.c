// coundigs.c
#include <stdio.h>

/* count digs, white space, others... */
int main() {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits = ");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

/*
    `if (c >= '0' && c <= '9')`
    determines whether the character in c is a digit. If it is, the numeric value of that digit is
        c - '0'
    This works only if '0', '1', ..., '9' have consecutive increasing values. Fortunately,
    this is true for all character sets.
*/