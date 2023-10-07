#include <stdio.h>
#include <stdlib.h>

void scanArr(int* array, size_t len) {
    for (size_t i = 0; i < len; i++) {
        scanf("%d", &array[i]);
    }
}

void printArr(int* array, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void nullCheck(void* ptr) {
    if (!ptr) {
        puts("Memory allocation error");
        exit(0);
    }
}

int* concatArr(int* arr1, size_t len1, int* arr2, size_t len2, size_t* resLen) {
    int* resArr = malloc(sizeof(int) * (len1 + len2));
    nullCheck(resArr);
    size_t currInd = 0;
    for (size_t i = 0; i < len1; resArr[currInd++] = arr1[i++])
        ;
    for (size_t i = 0; i < len2; resArr[currInd++] = arr2[i++])
        ;
    *resLen = currInd;
    return resArr;
}

int* findSubArr(int* arr1, size_t len1, int* arr2, size_t len2) {
    if (len2 > len1) {
        return NULL;
    }
    for (size_t i = 0; i <= (len1 - len2); i++) {
        size_t j = 0;
        if (arr1[i] == arr2[j]) {
            for (; j < len2 && (arr1[i + j] == arr2[j]); j++)
                ;
            if (j == len2) {
                return &arr1[i];
            }
        }
    }
    return NULL;
}

void removeSubArr(int** arr1, size_t* len1, int* arr2, size_t len2) {
    int* subArr = NULL;
    while ((subArr = findSubArr(*arr1, *len1, arr2, len2))) {
        int* endSubArr = subArr + len2;
        // Reusing concatArr function to join 2 arrays: before subArr and after
        int* arr3 = concatArr(*arr1, subArr - *arr1, endSubArr,
                              *arr1 + (*len1) - endSubArr, len1);
        free(*arr1);
        *arr1 = arr3;
    }
}

void performSubArrays() {
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

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

int combinations(int n, int k) { return fact(n) / fact(k) / fact(n - k); }

int** triangleArray(size_t* rows) {
    scanf("%zu", rows);
    int** triangleArr = malloc(sizeof(int*) * *rows);
    nullCheck(triangleArr);
    for (size_t i = 0; i < *rows; i++) {
        triangleArr[i] = malloc(sizeof(int) * (i + 1));
        nullCheck(triangleArr[i]);
    }
    return triangleArr;
}

void destroyTriangleArray(int** arr, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

void fillWithBinomial(int** arr, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < i + 1; j++) {
            arr[i][j] = combinations(i, j);
        }
    }
}

void printTriangleArr(int** arr, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t space = 0; space < rows - i - 1; space++) {
            printf(" ");
        }
        for (size_t j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void performTriangle() {
    size_t rows;
    int** arr = triangleArray(&rows);
    fillWithBinomial(arr, rows);
    printTriangleArr(arr, rows);
    // Output:
    //     1
    //    1 1
    //   1 2 1
    //  1 3 3 1
    // 1 4 6 4 1
    destroyTriangleArray(arr, rows);
}

#define INIT_CAPACITY 16
int* evilScanArr(size_t* size, size_t* capacity) {
    int* array = malloc(sizeof(int) * *capacity);
    nullCheck(array);
    int value;
    do {
        scanf("%d", &value);
        if (*size == *capacity) {
            *capacity += *size;
            array = realloc(array, *capacity);
            nullCheck(array);
        }
        array[(*size)++] = value;
    } while (value);
    return array;
}

int main(void) {
    return 0;
}
