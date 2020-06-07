// str_len.c
#include <stdio.h>

/**
 * str_ken: return length of string s
 */
int str_len(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/*
    Since s is a pointer, incrementing it is perfectly legal; s++ has no effect on the character string
    in the function that called strlen , but merely increments strlen 's private copy of the
    pointer.

    As formal parameters in a function definition,
        char s[];
    and
        char *s;
    are equivalent; we prefer the latter because it says more explicitly that the variable is a
    pointer. When an array name is passed to a function, the function can at its convenience
    believe that it has been handed either an array or a pointer, and manipulate it accordingly. It
    can even use both notations if it seems appropriate and clear.

    It is possible to pass part of an array to a function, by passing a pointer to the beginning of the
    subarray. For example, if a is an array,
        f(&a[2])
    and
        f(a + 2)
    both pass to the function f the address of the subarray that starts at a[2] . Within f , the
    parameter declaration can read.
        f(int arr[]) { ... }
    or
        f(int *arr) { ... }

    So as far as f is concerned, the fact that the parameter refers to part of a larger array is of no
    consequence.

    If one is sure that the elements exist, it is also possible to index backwards in an array; p[-1] ,
    p[-2] , and so on are syntactically legal, and refer to the elements that immediately precede
    p[0] . Of course, it is illegal to refer to objects that are not within the array bounds.
*/

/**
 * str_len_2: return length of string s
 */
int str_len_2(char *s) {
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}