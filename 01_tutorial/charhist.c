// wordhist.c
/*
 * this program prints a histogram of the lengths
 * of the words in its input. Horizontal bars.
 */
#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    int char_hist[150];          // vector for the histogram

    // init word histogram all to 0
    for (int i = 0; i < 150; i++) {
        char_hist[i] = 0;
    }

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        if (c > 31 && c < 127) {
            char_hist[c]++;
        }
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    
    // print hist
    printf("\n\n            Frequencies of chars of input words: \n");
    for (int i = 32; i < 127; i++) {
        printf("%2c : ", i);
        for (int j = 0; j < char_hist[i]; j++) {
            if (j % 3 == 0)
                printf("|");
        }
        printf("\n");
    }
}