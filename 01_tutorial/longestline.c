// longestline.c
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);


/* print the longest input line */
int main() {
    int len;                // current line length
    int max;                // maximum length seen so far
    int loss_flag = 0;
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here
    char c;

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
            if (max == (MAXLINE - 1) && longest[max] != '\n') {
                loss_flag = 1;
                while ((c = getchar()) != EOF && (c != '\n')) {
                    max++;
                }
            }
        }
    if (max > 0) {    // there was a line 
        printf("\n\n-*- longest line:\n%s\n", longest);
        if (loss_flag) {
            printf("\n-*- longest line length was: %d", max);
            printf(" | total chars lost: %d \n", max - 999);
        }
    }   

    return 0;
}

/* getline: read a line into s, return lentgh */
int get_line(char line[], int maxline) {
    int c, i;
    // we iterate until MAXLINE - 1 because we need the last
    // space in the array to input null char: '\0', to indicate
    // the end of the array. 
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy `from` into `to`; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) !=  '\0')
        ++i;
    return;
}