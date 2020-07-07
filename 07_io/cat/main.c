// main.c
#include <stdio.h>
#include <stdlib.h>
#define getchar()   getc(stdin)
#define putchat()   putc((c), stdout)


/**
 * cat: concatenate files, version 1
 */
int main(int argc, char *argv[]) {
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];

    if (argc == 1)      // no args; copy standard input
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}


/**
 * filecopy: copy file ifp to file ofp
 */
void filecopy(FILE *ifp, FILE *ofp) {
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}


/**
 * Within main , return expr is equivalent to exit ( expr ). exit has the advantage that it can be
 * called from other functions, and that calls to it can be found with a pattern-searching program
 */
