// str_cmp.c
/**
 * routine that we will examine is strcmp(s,t) , which compares the character
 * strings s and t , and returns negative, zero or positive if s is lexicographically less than, equal
 * to, or greater than t . The value is obtained by subtracting the characters at the first position
 * where s and t disagree.
 */

/**
 * str_cmp: return < 0 if s < t, 0 if s == t, > 0 if s > t
 */
int str_cmmp(char *s, char *t) {
    int i;
    for (i = 0; s[i] == t[i]; t++) {
        if (s[i] == '\0')
            return 0;
    }
    return s[i] - t[i];
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

