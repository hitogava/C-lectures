#include <stdio.h>
#include <limits.h>

int var1, var2;

void task1 () {
    puts ("Hello world!\n");
}

void task2 () {
    scanf ("%d", &var1);
    scanf ("%d", &var2);
    printf("%d + %d = %d\n",var1, var2, var1 + var2);
    printf("%d - %d = %d\n",var1, var2, var1 - var2);
    printf("%d * %d = %d\n",var1, var2, var1 * var2);
    // If var2 == 0
    // [1] 6938 floating point exception (core dumped)  ./a.out
    printf("%d / %d = %d\n",var1, var2, var1 / var2);
    printf("%d < %d = %d\n",var1, var2, var1 < var2);
    printf("%d <= %d = %d\n",var1, var2, var1 <= var2);
    printf("%d > %d = %d\n",var1, var2, var1 > var2);
    printf("%d >= %d = %d\n",var1, var2, var1 >= var2);
    printf("%d == %d = %d\n",var1, var2, var1 == var2);
    printf("%d && %d = %d\n",var1, var2, var1 && var2);
    printf("%d || %d = %d\n",var1, var2, var1 || var2);
    printf("~%d = %d\n", var1, ~var1);
    printf("!%d = %d\n",var1, !var1);
    printf("%d & %d = %d\n",var1, var2, var1 & var2);
    printf("%d | %d = %d\n",var1, var2, var1 | var2);
    printf("%d ^ %d = %d\n",var1, var2, var1 ^ var2);
    // signed int overflow = 2147483647 + 1;
    signed int overflow = INT_MAX + 1;
    printf("%d\n", overflow);
}

int main() {
    task2();
    return 0;
}
