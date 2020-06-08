// init_pointer_arrays.c
#include <stdio.h>
#include <stdlib.h>

/**
 * month_name: return name of n-th month
 */
char *month_name(int n) {
    static char *name[] = {
        "Illegal month",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

/**
 * The declaration of name , which is an array of character pointers, is the same as lineptr in the
 * sorting example. The initializer is a list of character strings; each is assigned to the
 * corresponding position in the array. The characters of the i -th string are placed somewhere,
 * and a pointer to them is stored in name[i] . Since the size of the array name is not specified,
 * the compiler counts the initializers and fills in the correct number.
 */
