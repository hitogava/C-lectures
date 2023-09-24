#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/resource.h>
// #include <unistd.h>

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

void boo() {
    int a;
    printf("Address of a inside boo %p\n", &a);
}
void foo() {
    boo();
}
// problem 1
void perform_problem_1 () {
    boo();
    foo();
}

//problem 5
void overflowFoo (char* head, char* curr) {
    char v;
    curr = &v;
    printf("%td\n", head - curr);
    return overflowFoo(head, curr);
}
void perform_problem_5 () {
    char h;
    overflowFoo(&h, NULL);
    struct rlimit rl;
    getrlimit(RLIMIT_STACK, &rl);
    printf("%lu\n", rl.rlim_cur);
}
int main (int argc, char** argv) {
    return 0;
}
