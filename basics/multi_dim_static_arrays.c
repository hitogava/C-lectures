#include <stdio.h>
#include <stdlib.h>

const size_t MATRIX_SIZE = 4;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void readMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            scanf("%d\n", &(matrix[i][j]));
        }
    }
}

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void mainDiagonalReverse(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (size_t i = 0, j = 0; i < MATRIX_SIZE; i++, j++) {
        for (size_t k = 0; k < i; k++) {
            swap(&matrix[i][k], &matrix[k][i]);
        }
    }
}

int main(void) {
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    readMatrix(matrix);
    printMatrix(matrix);
    printf("\n");
    mainDiagonalReverse(matrix);
    printMatrix(matrix);
}
