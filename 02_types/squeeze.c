// squeeze.c

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;
    for (i = j; s[i] != '\0'; i++) {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

/**
 * Each time a non-c occurs, it sis copied into the current j,  and only then
 * is j incremented to be ready fo the next character. this is equivalent to

   if  (s[i] != c) {
       s[j] = s[i];
       j++;
   }
 */
