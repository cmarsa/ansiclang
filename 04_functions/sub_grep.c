// sub_grep.c
#include <stdio.h>
#define MAXLINE 1000        // maximum input line length */
/*
    Functions break large computing tasks into smaller ones, and enable people to build on what
    others have done instead of starting over from scratch. Appropriate functions hide details of
    operation from parts of the program that don't need to know about them, thus clarifying the
    whole, and easing the pain of making changes.

    C has been designed to make functions efficient and easy to use; C programs generally consist
    of many small functions rather than a few big ones. A program may reside in one or more
    source files. Source files may be compiled separately and loaded together, along with
    previously compiled functions from libraries. We will not go into that process here, however,
    since the details vary from system to system.
*/

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";     // pattern to search for

/**
 * find all lines matching pattern
 */
int main() {
    char line[MAXLINE];
    int found = 0;

    while (get_line(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return 0;
}


/**
 * get_line: get line into s return length
 */
int get_line(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    
    s[i] = '\0';
    return i;
}


/**
 * strindex: return idnex of t in s, -1 if none
 */
int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}