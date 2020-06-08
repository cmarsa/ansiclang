// main.c
/**
 * a program that evalutates reverse polish expressions
 * from the command line, where each operator or operand
 * is a separate argument.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "expr.h"

// function prorotypes
void push(double);
double pop(void);
int getop(char *s);
int getop_dev(char *s);



/**
 * reverse polish calculator
 */
int main(int argc, char *argv[]) {
    int type;
    double op2;
    int valid_state = 1;
    for (int i = 1; i < argc; i++) {
        if (!valid_state)
            break;
        switch (type = getop(argv[i])) {
            case NUMBER:
                push(atof(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else {
                    printf("Error: zero divisor.\n");
                    valid_state = 0;
                }
                break;
            default:
                printf("Error: unkown command %s\n", argv[i]);
                valid_state = 0;
                break;
        }
    }
    // all arguments have been parsed
    // now time to print result
    if (valid_state)
        printf("\t%.8g\n", pop());
    else
        printf("Invalid syntax.\n");
    
    return 0;
}


/**
 * getop_dev
 */
int getop(char *s) {

    // check for first character in the argument
    // passed
    if (!isdigit(s[0]) && s[0] != '.' && s[1] == '\0') {
        // check if there are any other chars
        // to validate syntax
        return s[0];
    }
    
    while (*s != '\0') {
        if (!isdigit(*s) && *s != '.')
            return 'i';
        s++;
    }
    
    return NUMBER;       
}