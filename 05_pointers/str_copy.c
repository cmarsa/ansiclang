// str_copy.c
#include <stdlib.h>

/**
 * str_copy_1: copy t to s; array subscript version
 */
void str_copy_1(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/**
 * str_copy_2: copy t to s; pointer version
 */
void str_copy_2(char *s, char *t) {
    int i = 0;
    while ((*s = *t) != '\0') {
        s++;
        i++;
    }
}

/**
 * In practice, strcpy would not be written as we showed it above. Experienced C programmers
 * would prefer:
 * str_copy: copy t to s; pointer version 2
 */
void str_copy(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}

/**
 * As the final abbreviation, observe that a comparison against '\0' is redundant, since the
 * question is merely whether the expression is zero. So the function would likely be written as
 * str_copy: copy t to s; pointer version 3
 */
void str_copy(char *s, char *t) {
    while (*s++ = *t++)
        ;
}