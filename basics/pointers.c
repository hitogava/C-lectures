#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>

void swap (int64_t* a, int64_t* b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void evil_scanf (int* p0, int* p1, int* p2) {
    int n0,n1,n2;
    scanf("%d", &n0);
    scanf("%d", &n1);
    scanf("%d", &n2);
    int tmp = *p0;
    *p0 = n0;
    if (n0 > 0) {
        *p1 = n1;
        *p2 = n2;
    } else {
        *p2 = n0 * n1 * n2 * (*p1) * (*p2);
        *p1 = tmp;
    }
}

void perform_evil_scanf () {
    int x = 9;
    int y = 11;
    int z = 13;
    int* px = &x;
    int* py = &y;
    int* pz = &z;
    evil_scanf(px, py, pz);
    printf("%d %d %d\n", x, y, z);
}

int* foo() {
    int local = 10;
    int *plocal = &local;
    return plocal;
}

void perform_problem_1 () {
    // Trying to return a pointer to local variable "local" in foo()
    // Should works because stack hasn't been overwritten by other functions
    int* p = foo();
    printf("%d\n", *p);

    // But now stack is overwritten by calling funcion perform_evil_scanf()
    // Still undefined behavior
    p = foo();
    perform_evil_scanf();
    printf("%d\n", *p);

}

int main (int argc, char** argv) {
    return 0;
}
