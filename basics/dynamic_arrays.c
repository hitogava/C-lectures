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

int* concatArr(int* arr1, size_t len1, int* arr2, size_t len2, size_t* resLen) {
    int* resArr = malloc (sizeof(int) * (len1 + len2));
    // null checking
    size_t currInd = 0;
    for (size_t i = 0; i < len1; resArr[currInd++] = arr1[i++]) ;
    for (size_t i = 0; i < len2; resArr[currInd++] = arr2[i++]) ;
    *resLen = currInd;
    return resArr;
}

int main (void) {
    size_t len1;
    size_t len2;
    scanf("%zu", &len1);
    scanf("%zu", &len2);
    int* arr1 = malloc(sizeof(int) * len1);
    int* arr2 = malloc(sizeof(int) * len2);

    scanArr(arr1, len1);
    scanArr(arr2, len2);

    printArr(arr1, len1);
    printArr(arr2, len2);

    size_t len3;
    int* arr3 = concatArr(arr1, len1, arr2, len2, &len3);
    printArr(arr3, len3);
    return 0;
}
