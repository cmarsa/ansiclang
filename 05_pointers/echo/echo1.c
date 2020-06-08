// echo1.c
#include <stdio.h>

/**
 * echo command-line arguments; version 1
 */
int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}