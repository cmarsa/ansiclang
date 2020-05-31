// alter_squeeze.c
#include <stdio.h>
#define TRUE 1;
#define FALSE 0;


// function prototypes
void substr_squeeze(char[], char[]);
void test_substr_squeeze();


int main() {
    test_substr_squeeze();
}


/**
 * Deletes each character in
 * s1 that matches any character in the string s2 .
 */
void substr_squeeze(char s1[], char s2[]) {
    int i, j, k;
    int is_match;
    for (i = j = 0; s1[i] != '\0'; i++) {
        is_match = FALSE;
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                is_match = TRUE;
                break;
            }
            else {
                ;
            }
        }
        if (!is_match) {
            s1[j] = s1[i];
            j++;
        }
    }
    s1[j] = '\0';
}


void test_substr_squeeze() {
    char test_string[] = "Hi, this is the test string.";
    char substr[] = "et";

    printf("test string: %s \n", test_string);
    printf("substring to remove: %s\n", substr);

    substr_squeeze(test_string, substr);

    printf("final test_string: %s\n", test_string);
}

