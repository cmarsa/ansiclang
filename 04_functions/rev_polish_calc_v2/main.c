// reverse_polish_calc.c
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100  // signal that a number was found

// function prorotypes
int getop(char[]);
void push(double);
double pop(void);


/**
 * reverse polish calculator
 */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
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
                else
                    printf("Error: zero divisor.\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unkown command %s\n", s);
                break;
        }
    }

    return 0;
}