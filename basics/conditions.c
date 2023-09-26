#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int var1, var2;

void calc() {
    scanf("%d", &var1);
    scanf("%d", &var2);
    printf("%d + %d = %d\n", var1, var2, var1 + var2);
    printf("%d - %d = %d\n", var1, var2, var1 - var2);
    printf("%d * %d = %d\n", var1, var2, var1 * var2);
    if (var2 == 0) {
        puts("Division by zero");
    } else {
        printf("%d / %d = %d\n", var1, var2, var1 / var2);
    }
    if (var2 == 0) {
        puts("Division by zero");
    } else {
        printf("%d %% %d = %d\n", var1, var2, var1 % var2);
    }
    printf("%d < %d = %d\n", var1, var2, var1 < var2);
    printf("%d <= %d = %d\n", var1, var2, var1 <= var2);
    printf("%d > %d = %d\n", var1, var2, var1 > var2);
    printf("%d >= %d = %d\n", var1, var2, var1 >= var2);
    printf("%d == %d = %d\n", var1, var2, var1 == var2);
    printf("%d && %d = %d\n", var1, var2, var1 && var2);
    printf("%d || %d = %d\n", var1, var2, var1 || var2);
    printf("~%d = %d\n", var1, ~var1);
    printf("!%d = %d\n", var1, !var1);
    printf("%d & %d = %d\n", var1, var2, var1 & var2);
    printf("%d | %d = %d\n", var1, var2, var1 | var2);
    printf("%d ^ %d = %d\n", var1, var2, var1 ^ var2);
    // signed int overflow = 2147483647 + 1;
    signed int overflow = INT_MAX + 1;
    printf("%d\n", overflow);
}
void leap_year() {
    unsigned short year;
    scanf("%hu", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        printf("%hu is a leap year\n", year);
    } else {
        printf("%hu is not a leap year\n", year);
    }
}
void fizz_buzz(unsigned long n) {
    for (size_t i = 0; i <= n; i++) {
        if (i % 3 == 0) {
            printf("fizz ");
        }
        if (i % 5 == 0) {
            printf("buzz ");
        }
        if (i % 3 != 0 && i % 5 != 0) {
            printf("%zu ", i);
        }
    }
    printf("\n");
}
void square(unsigned long n) {
    // 4
    // 0 1
    // 2 3
    for (size_t i = 0; i < n * n; i++) {
        printf("%lu ", i);
        if ((i + 1) % n == 0) {
            printf("\n");
        }
    }
}
void triangle(unsigned long n) {
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < n * (n + 1) / 2) {
        k = 0;
        j++;
        while (k < j) {
            printf("%lu ", i);
            i += 1;
            k++;
        }
        printf("\n");
    }
}
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
void prime_numbers() {
    unsigned long long n;
    scanf("%llu", &n);
    if (n < 2) {
        return;
    }
    for (unsigned long long i = 2; i <= n; i++) {
        if (prime(i)) {
            printf("%llu ", i);
        }
    }
}
bool is_lucky(unsigned long n) {
    int first_digits = 0;
    int last_digits = 0;
    unsigned long t = n;
    for (size_t i = 0; i < 3; i++) {
        last_digits += t % 10;
        t = t / 10;
    }
    for (size_t i = 0; i < 3; i++) {
        first_digits += t % 10;
        t = t / 10;
    }
    return (n >= pow(10, 5) && n < pow(10, 6) && first_digits == last_digits);
}
void lucky_cards() {
    unsigned long l, r;
    scanf("%lu", &l);
    scanf("%lu", &r);
    if (l > r) {
        printf("L > R, error!\n");
        return;
    }
    for (size_t i = l; i <= r; i++) {
        if (is_lucky(i)) {
            printf("%zu ", i);
        }
    }
}
int main(int argc, char** argv) { return EXIT_SUCCESS; }
