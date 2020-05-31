// bitcount.c

/* counts the number of 1-bits in its integer arg */
int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01)
            b++;
    return b;
    }
}