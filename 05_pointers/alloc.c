// alloc.c
#define ALLOCSIZE 10000             // size of available space

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position


char *alloc(int n) {
    // it fits
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return alloc - n;
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

/*
    In general a pointer can be initialized just as any other variable can, though normally the only
    meaningful values are zero or an expression involving the address of previously defined data
    of appropriate type. The declaration
        static char *allocp = allocbuf;
    defines allocp to be a character pointer and initializes it to point to the beginning of
    allocbuf , which is the next free position when the program starts. This could also have been
    written
        static char *allocp = &allocbuf[0];
    since the array name is the address of the zeroth element.

    The test
    // it fits
    if (allocbuf + ALLOCSIZE - allocp >= n)

    checks if there's enough room to satisfy a request for n characters. If there is, the new value of
    allocp would be at most one beyond the end of allocbuf . If the request can be satisfied,
    alloc returns a pointer to the beginning of a block of characters (notice the declaration of the
    function itself). If not, alloc must return some signal that there is no space left. C guarantees
    that zero is never a valid address for data, so a return value of zero can be used to signal an
    abnormal event, in this case no space.

    Pointers and integers are not interchangeable. Zero is the sole exception: the constant zero
    may be assigned to a pointer, and a pointer may be compared with the constant zero. The
    symbolic constant NULL is often used in place of zero, as a mnemonic to indicate more clearly
    that this is a special value for a pointer. NULL is defined in <stdio.h>.

*/


/*

    Tests like
        // it fits
        if (allocbuf + ALLOCSIZE - allocp >= n)
    and 
        if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    show several important facets of pointer arithmetic. First, pointers may be compared under
    certain circumstances. If p and q point to members of the same array, then relations like == ,
    != , < , >= , etc., work properly. For example
        p < q
    is true if p points to an earlier element of the array than q does. Any pointer can be
    meaningfully compared for equality or inequality with zero. But the behavior is undefined for
    arithmetic or comparisons with pointers that do not point to members of the same array.
    (There is one exception: the address of the first element past the end of an array can be used in
    pointer arithmetic.)

    Second, we have already observed that a pointer and an integer may be added or subtracted.
    The construction
        p + n
    means the address of the n -th object beyond the one p currently points to. This is true
    regardless of the kind of object p points to; n is scaled according to the size of the objects p
    points to, which is determined by the declaration of p . If an int is four bytes, for example, the
    int will be scaled by four.

    Pointer subtraction is also valid: if p and q point to elements of the same array, and p<q , then
    q-p+1 is the number of elements from p to q inclusive. 
*/
