// qsort.c
#include <stdio.h>

// function prototypes
void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);
int test_qsort(void); 
void print_array(int array[], int size);


int main() {
    test_qsort();
}


int test_qsort() {
    int array[] = {3, 5, 6, 9, 1, 10, 2, 0, 8, 1};
    int SIZE = (int) sizeof(array) / sizeof(array[0]);

    printf("The initial array is:\n");
    print_array(array, SIZE);

    printf("Sorting the array ...\n");

    qsort(array, 0, 9);

    printf("The final array is:\n");
    print_array(array, SIZE);

    return 0;
}


void print_array(int array[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * qsort: sort v[left] ... v[right] into increasing order
 */
void qsort(int v[], int left, int right) {
    int i, last;
    
    if (left >= right)
        return;
    
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}


/**
 * swap: interchange v[i] and v[j]
 */
void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}