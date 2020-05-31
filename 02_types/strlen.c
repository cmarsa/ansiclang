// strlen.c
// a version of strlen

/**
 * Technically, a string constant is an array of characters. The internal representation of a string
 * has a null character '\0' at the end, so the physical storage required is one more than the
 * number of characters written between the quotes. This representation means that there is no
 * limit to how long a string can be, but programs must scan a string completely to determine its
 * length. The standard library function strlen(s) returns the length of its character string
 * argument s , excluding the terminal '\0' . Here is our version:
 **/

/**
 * str_len: return length of s
 **/
int str_len(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return 0;
}
