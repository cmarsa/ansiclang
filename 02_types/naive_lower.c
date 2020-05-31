// lower.c
/**
 * Another example of char to int conversion is the function lower , which maps a single
 * character to lower case for the ASCII character set . If the character is not
 * an upper case letter, lower returns it unchanged.
 */


/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
