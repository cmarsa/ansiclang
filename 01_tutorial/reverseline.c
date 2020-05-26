// reverseline.c
#include <stdio.h>

void reverse(char *sarray, int size);

int main() {
    char array[6] = {'m', 'a', 'r', 'c', 'o'};

    printf("Initial array: \n");
    for (int i = 0; i < 6; i++) {
        printf("%c", array[i]);
    }
    printf("\n");

    printf("Reversing array ...\n");
    reverse(array, 6);

    printf("Reversed array: \n");
    for (int i = 0; i < 6; i++) {
        printf("%c", array[i]);
    }
    printf("\n");

    return 0;
}


void reverse(char *sarray, int size) {
    char temporal;
    for (int first = 0, last = size - 1; first < last; first++, last--) {
        temporal = sarray[first];
        sarray[first] = sarray[last];
        sarray[last] = temporal; 
    }
}