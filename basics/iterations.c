#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
bool prime(unsigned long long n) {
    if (n <= 1) {
        return false;
    }
    size_t i = 2;
    while (i <= sqrt(n)) {
        if (n % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}
void problem_1(unsigned long long n) {
    if (n < 2) {
        return;
    }
    for (unsigned long long i = 2; i <= n; i++) {
        if (prime(i)) {
            printf("%llu ", i);
        }
    }
}
unsigned int divs_amount(unsigned long long n) {
    if (n < 1) {
        printf("Need positive value\n");
        exit(0);
    }
    unsigned int count = 0;
    for (size_t i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}
void problem_2() {
    uint64_t n;
    scanf("%" SCNu64 "\n", &n);
    printf("%u\n", divs_amount(n));
}
void swap(uint64_t *a, uint64_t *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
uint64_t gcd(uint64_t a, uint64_t b) {
    while (b) {
        a %= b;
        swap(&a, &b);
    }
    return a;
}
void problem_3() {
    uint64_t a;
    uint64_t b;
    scanf("%" SCNu64, &a);
    scanf("%" SCNu64, &b);
    printf("%" PRIu64 "\n", gcd(a, b));
}
int main(int argc, char **argv) {
    // problem_3();
    return 0;
}
