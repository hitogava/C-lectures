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

void nullCheck(void* ptr) {
    if (!ptr) {
        puts ("Memory allocation error");
        exit(0);
    }
}

int* concatArr(int* arr1, size_t len1, int* arr2, size_t len2, size_t* resLen) {
    int* resArr = malloc (sizeof(int) * (len1 + len2));
    nullCheck(resArr);
    // null checking
    size_t currInd = 0;
    for (size_t i = 0; i < len1; resArr[currInd++] = arr1[i++]) ;
    for (size_t i = 0; i < len2; resArr[currInd++] = arr2[i++]) ;
    *resLen = currInd;
    return resArr;
}

int* findSubArr (int* arr1, size_t len1, int* arr2, size_t len2) {
    if (len2 > len1) { return NULL; }
    for (size_t i = 0; i <= (len1 - len2); i++) {
        size_t j = 0;
        if (arr1[i] == arr2[j]) {
            for (; j < len2 && (arr1[i+j] == arr2[j]); j++) ;
            if (j == len2) { 
                return &arr1[i];
            }
        }
    }
    return NULL;
}

// 0 1 8 7 4 1 8 7 6
void removeSubArr (int** arr1, size_t* len1, int* arr2, size_t len2) {
    int* subArr = NULL;
    while ((subArr = findSubArr(*arr1, *len1, arr2, len2))) {
        int* endSubArr = subArr + len2;
        // Reusing concatArr function to join 2 arrays: before subArr and after
        int* arr3 = concatArr(*arr1, subArr - *arr1, endSubArr, *arr1 + (*len1) - endSubArr, len1);
        free(*arr1);
        *arr1 = arr3;
    }
}

void perform () {
    size_t len1;
    size_t len2;
    scanf("%zu", &len1);
    scanf("%zu", &len2);
    int* arr1 = malloc(sizeof(int) * len1);
    int* arr2 = malloc(sizeof(int) * len2);

    nullCheck(arr1);
    nullCheck(arr2);

    scanArr(arr1, len1);
    scanArr(arr2, len2);

    printArr(arr1, len1);
    printArr(arr2, len2);

    removeSubArr(&arr1, &len1, arr2, len2);
    printArr(arr1, len1);

    free(arr1);
    free(arr2);
}

int main (void) {
    perform();
    return 0;
}
