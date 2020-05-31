// getbits.c
#include <stdio.h>

// function prototypes
unsigned getbits(unsigned, int, int);
void test_getbits();

int main() {
    test_getbits();
}


/* getbits: returns the (right adjusted) n-bit field of x that begins at position p . */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

void test_getbits() {
    unsigned b, x = 30456;
    int p = 4, n = 3;

    b = getbits(x, p, n);
    
    printf("%d\n", b);
}