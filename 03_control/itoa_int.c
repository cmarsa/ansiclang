// itoa_int.c
#include <stdio.h>
#include <string.h>

// function prototypes
void itoa(int n, char s[]);
void reverse(char *sarray, int size);
void print_str(char *str);
void test_itoa();


int main() {
    test_itoa();

    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;

    do {
        s[i++] = n % 10 + '0';  // get next digit
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, strlen(s));
}


void reverse(char *sarray, int size) {
    char temporal;
    for (int first = 0, last = size - 1; first < last; first++, last--) {
        temporal = sarray[first];
        sarray[first] = sarray[last];
        sarray[last] = temporal; 
    }
}

void print_str(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}


void test_itoa() {
    int i = 8686534;
    char i_string[255];

    printf("integer type: %d\n", i);

    itoa(i, i_string);

    printf("charr array type: ");
    print_str(i_string);
}