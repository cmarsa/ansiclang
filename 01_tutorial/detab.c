// detab.c
#include <stdio.h>
/*
    This is my version of detab.c
    I think this can be optimized in many ways, but i made the store_input function
    for practicing and understanging purpouses of the arrays and strings.

    The program receives an input (of maximum 3000 chars), and then prints
    out a parsed version of the input with a number of * instead of the \t char.
    Can be easily changed to put spaces (' ') instead of '*'s.

    It will be better if the for statements in the functions
    `store_input` and `parse_input` are changed for while loops with conditional (str[i] != '\0')
    as in function `print_str`. Indeed, theres a break statement to not surpass the '\0' char
    and end the loop. It will be more elegant on a while I believe... Or simply not to 
    assign the '\0' char in the `input_str` array in the `store_input` function,
    I think this is what was causing me a "stack smashing error" during runtime.
 */

#define TAB 4
#define MAX_INPUT_SIZE 3000

// function prototypes
void store_input(char *str);
void parse_input(char *input_str, char *parsed_str);
void print_str(char *str);


/* main: receives an input and prints a parsed text
 *       where \t are removed and replaced by whitespace.
 */
int main() {

    char input_str[MAX_INPUT_SIZE] = " ";
    char parsed_str[MAX_INPUT_SIZE] = " ";

    // store input
    store_input(input_str);

    // print stored input
    print_str(input_str);

    // parse the input string
    parse_input(input_str, parsed_str);

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


void parse_input(char *input_str, char *parsed_str) {
    int col_pos = 1, n_blanks;      // col_pos: counter for column position; n_blanks: nubmer of white spaces
    int iindex = 0, pindex = 0;         // iindex: index for input string, pindex: index for parsed string
    for (iindex = 0; iindex < MAX_INPUT_SIZE - 1; iindex++) {
        if (input_str[iindex] == '\0')
            break;
        if (input_str[iindex] == '\n') {
            col_pos = 1;
        }
        if (input_str[iindex] == '\t') {
            n_blanks = TAB - ((col_pos - 1) % TAB);
            for (int i = 0; i < n_blanks; i++) {
                parsed_str[pindex] = '*';
                col_pos++;
                pindex++;
            }
        }
        else {
            parsed_str[pindex] = input_str[iindex];
            pindex++;
            col_pos++;
        }
    }
}