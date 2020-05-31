// strcat.c
/**
 * consider the standard function strcat(s,t) , which concatenates the 
 * string t to the end of string s . strcat assumes that there is enough space in s to hold the 
 * combination. As we have written it, strcat returns no value; the standard library version 
 * returns a pointer to the resulting string.
 */


/* strcat: concatenate t to end of s; s msut be big enough */
void strcat(char s[], char t[]) {
    int i, j;
    i = j = 0;

    while (s[i] != '\0')                // find end of s
        i++;
    while ((s[i++] = t[j++]) != '\0')   // copy t
        ;
}

/**
 * As each member is copied from t to s , the postfix ++ is applied to both i and j to make sure
 * that they are in position for the next pass through the loop.
 */
