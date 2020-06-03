// escape_chars.c
#include <stdio.h>

#define MAX_INPUT_SIZE 3000

// function prototypes
void store_input(char *str);
void escape(char *input_str, char *parsed_str);
void print_str(char *str);


/* main: receives an input and prints a parsed text
 *       where escape chars are replaced by \n and \t.
 */
int main() {

    char input_str[MAX_INPUT_SIZE] = " ";
    char parsed_str[MAX_INPUT_SIZE] = " ";

    // store input
    store_input(input_str);

    // print stored input
    print_str(input_str);

    // parse the input string
    escape(input_str, parsed_str);

    // print stored input
    print_str(parsed_str);
    
    return 0;
}


void print_str(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}


void store_input(char *str) {
    char c;
    for (int i = 0; i < MAX_INPUT_SIZE - 1; i++) {
        if ((c = getchar()) != EOF)
            str[i] = c;
        else {
            str[i] = '\0';
            break;
        }
    }
}


void escape(char *input_str, char *parsed_str) {
    char c;
    int iindex = 0, pindex = 0;         // iindex: index for input string, pindex: index for parsed string
    for (iindex = 0; iindex < MAX_INPUT_SIZE - 1; iindex++) {
        c = input_str[iindex];
        switch (c) {
            case '\0':
                break;
            case '\n':
                parsed_str[pindex++] = '\\';
                parsed_str[pindex++] = 'n';
                break;
            case '\t':
                parsed_str[pindex++] = '\\';
                parsed_str[pindex++] = 't';
                break;
            default:
                parsed_str[pindex++] = c;
                break;
        }
    }
}