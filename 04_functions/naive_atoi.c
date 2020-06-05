// naive_atoi.c
/**
 * Given `atoi`, properly declared, we could write
 * `atoi` (convert a tring to `int`) in terms of it
 * 
 * atoi: convert string s to integer using atof
 */
int atoi(char s[]) {
    double atof(char s[]);
    return (int) atof(s);
}
