// sub_grep.c
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


// function prototype
int get_line(char *line, int max);


/**
 * find: prnt lines that match pattern from 1st arg
 */
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else {
        while (get_line(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
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

/**
 * The standard library function strstr(s,t) returns a pointer to the first occurrence of the
 * string t in the string s , or NULL if there is none. It is declared in <string.h> .
 */
