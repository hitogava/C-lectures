#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int max(int x, int y) { return (x > y) ? x : y; }

int min(int x, int y) { return (x > y) ? y : x; }

size_t numDigits(int n) {
    if (n == 0) {
        return 1;
    }
    size_t counter = 0;
    while (n) {
        counter++;
        n /= 10;
    }
    return counter;
}

void scanfArr(int* array, size_t len) {
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

void revertArr(int* array, size_t len) {
    for (size_t i = 0; i < len / 2; i++) {
        swap(&array[i], &array[len - i - 1]);
    }
}

int maxInArr(int* array, size_t len) {
    int m = INT_MIN;
    for (size_t i = 0; i < len; i++) {
        m = max(m, array[i]);
    }
    return m;
}

int* findInArr(int* array, size_t len, int x) {
    for (size_t i = 0; i < len; i++) {
        if (array[i] == x) {
            return &array[i];
        }
    }
    return NULL;
}

void extractDigits(int* array, size_t len, int n) {
    int tmp = n;
    if (len < 10) {
        puts("Array length should be at least 10");
        return;
    }
    size_t nDigits = numDigits(n);
    for (int i = nDigits - 1; i >= 0; i--) {
        array[i] = tmp % 10;
        tmp /= 10;
    }
}

int compareArrays(int* arr1, size_t len1, int* arr2, size_t len2) {
    size_t minLen = min(len1, len2);
    for (size_t i = 0; i < minLen; i++) {
        if (arr1[i] < arr2[i]) {
            printf("%d %d\n", arr1[i], arr2[i]);
            return -1;
        } else if (arr1[i] > arr2[i]) {
            return 1;
        }
    }
    if (len1 == len2) {
        return 0;
    } else if (len1 < len2) {
        return -1;
    }
    return 1;
}

// problem 08.1
void performDynamicMemory1() {
    size_t len;
    scanf("%zu", &len);
    int* arr = (int*)malloc(len * sizeof(int));
    if (!arr) {
        puts("Memory allocation error");
        exit(0);
    }
    scanfArr(arr, len);
    printArr(arr, len);
    revertArr(arr, len);
    printArr(arr, len);
    printf("%p\n", findInArr(arr, len, 3));
}

// problem 08.2

void moveElements(int* src, size_t srcLen, int* dest) {
    for (size_t i = 0; i < srcLen; i++) {
        dest[i] = src[i];
    }
}

void performDynamicMemory2() {
    int value;
    int* src = NULL;
    size_t currIndex = 0;
    do {
        int* newArr = (int*)malloc((currIndex + 1) * sizeof(int));
        if (!newArr) {
            exit(0);
        }
        moveElements(src, currIndex, newArr);
        free(src);
        src = newArr;
        scanf("%d", &value);
        src[currIndex++] = value;
    } while (value);
    printArr(src, currIndex);
    free(src);
}

int main(int argc, char** argv) { return EXIT_SUCCESS; }
