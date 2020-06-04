// naive_atof.c
#include <ctype.h>
#include <stdio.h>

/* getline: read a line into s, return lentgh */
int get_line(char line[], int maxline) {
    int c, i;
    // we iterate until MAXLINE - 1 because we need the last
    // space in the array to input null char: '\0', to indicate
    // the end of the array. 
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}


/**
 * atof: convert string s to double
 * 
 * First, atof itself must declare the type of value it returns, since it is not int . The type name
 * precedes the function name.
 */
double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)     // skip white space
        ;
    
    sign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '-')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

/**
 * Second, and just as important, the calling routine must know that atof returns a non-int value. 
 * One way to ensure this is to declare atof explicitly in the calling routine. The declaration is
 * shown in this primitive calculator (barely adequate for check-book balancing), which reads
 * one number per line, optionally preceded with a sign, and adds them up, printing the running
 * sum after each input
 */

#define MAXLINE 100

/**
 * rudimentary calculator
 */
int main() {
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);

    printf("Rudimentary calculator.\nSums input floats:\n");
    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    
    return 0;
}