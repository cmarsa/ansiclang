// sort.c
/**
 * a stripped down version of the unix's program sort.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       // max # lines to be sorted

char *lineptr[MAXLINES];    // pointers to text lines

// function prototypes
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/**
 * sort input lines
 */
int main() {
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("Error: input to big to sort.\n");
        return 1;
    }
}


#define MAXLEN 1000         // max length of any input line
#define ALLOCSIZE 10000             // size of available space

// function prototypes
int get_line(char line[], int maxline);
char *alloc(int);

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position


char *alloc(int n) {
    // it fits
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    // not enough room
    else {
        return 0;
    }
}


void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
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
 * readlines: read input lines
 */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}


/**
 * writelines: write output lines
 */
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}


/**
 * qsort: sort v[left] ... v[right] into increasing order
 */
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)      // do nothing if array contains
        return;             // fewer than two elements

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);

    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/**
 * swap: interchange v[i] and v[j]
 */
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}