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
    int word_chars;             // counter for chars per word
    int word_hist[20];          // vector for the histogram

    // init word histogram all to 0
    for (int i = 0; i < 20; i++) {
        word_hist[i] = 0;
    }

    state = OUT;
    nl = nw = nc = 0;

    word_chars = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t')
            word_chars++;
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
            // increase hist bucket to 1 depending
            // size of word
            word_hist[word_chars]++;
            // reset to 0 the chars for next word
            word_chars = 0;
        }
    }
    
    // print hist
    printf("\n\nFrequencies of char size of input words: \n");
    for (int i = 1; i < 20; i++) {
        printf("%3d : ", i);
        for (int j = 0; j < word_hist[i]; j++) {
            printf("|");
        }
        printf("\n");
    }
}