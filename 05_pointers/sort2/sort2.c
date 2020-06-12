#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];        // pointers to text lines

// function prototypes
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void*, void*));
int num_cmp(char *, char *);
double atof(char s[]);


/**
 * sort input lines
 */
int main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    /**
     * In the call to qsort , strcmp and numcmp are addresses of functions. Since they are known to
     * be functions, the & is not necessary, in the same way that it is not needed before an array
     * name.
     */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void**) lineptr, 0, nlines - 1, (int (*)(void *, void*))(numeric ? num_cmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("input too big to sort\n");
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
 * 
 */
void qsort(void *v[], int left, int right, int (*comp)(void *, void*)) {
    /**
     * The fourth parameter of qsort is
     *      int (*comp)(void *, void *)
     * which says that comp is a pointer to a function that has two void * arguments and returns an
     * int .
     * 
     *      int *comp(void *, void *)  // WRONG 
     * says that comp is a function returning a pointer to an int , which is very different.
     */
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)      // do nothing if array contains
        return;             // fewer than two elements

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);

    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

/**
 * swap: interchange v[i] and v[j]
 */
void swap(void *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/**
 * str_cmp: return < 0 if s < t, 0 if s == t, > 0 if s > t
 *          (pointer version)
 */
int str_cmp(char *s, char *t) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/**
 * num_cmp: compare s1 and s2 numerically
 */
int num_cmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1  > v2)
        return 1;
    else
        return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)     // skip white space
        ;
    
    sign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '-')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}