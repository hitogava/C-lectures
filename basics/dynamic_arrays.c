#include <stdio.h>
#include <stdlib.h>

void scanArr (int* array, size_t len) {
    for (size_t i = 0; i < len; i++) {
        scanf ("%d", &array[i]);
    }
}

void printArr (int* array, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main (void) {
    size_t len1 = 7;
    size_t len2 = 2;
    int* arr1 = malloc(sizeof(int) * len1);
    int* arr2 = malloc(sizeof(int) * len2);
    scanArr(arr1, len1);
    scanArr(arr2, len2);
    printArr(arr1, len1);
    printArr(arr2, len2);
    return 0;
}
