// sub_grep_v2.c
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


// function prototype
int get_line(char *line, int max);

/**
 * find: print lines that match pattern from 1st arg
 */
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("finds: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else {
        while (get_line(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}


/* getline: read a line into s, return lentgh */
int get_line(char line[], int maxline) {
    int c, i;
    // we iterate until MAXLINE - 1 because we need the last
    // space in the array to input null char: '\0', to indicate
    // the end of the array. 
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}