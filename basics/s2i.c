#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>

typedef int32_t i32;
typedef int8_t i8;
typedef uint32_t ui32;

#define STRING_FORMAT_ERROR 1
#define STRING_BASE_ERROR 2
#define print_i32(n) printf("%" PRId32 "\n",n)

void ensure_format(char ch, ui32 base, jmp_buf* state) {
    i8 digit = ch - '0';
    if (digit >= base) {
        longjmp(*state, STRING_FORMAT_ERROR);
    }
}

i32 s2i(const char* string, ui32 base, jmp_buf* state) {
    i32 result = 0;
    ui32 power = 0;
    size_t string_len = strlen(string);
    // 1 -> positive, -1 -> negative
    i8 sign = string_len > 0 && string[0] == '-' ? -1 : 1;
    for (int i = string_len - 1; i >= 0; i--) {
        if (i == 0 && string[i] == '-') { continue; }
        i8 digit = string[i] - '0';
        ensure_format(string[i], base, state);
        result += digit * (i32)(pow(base,power++));
    }
    result *= sign;
    return result;
}

int main() {
    jmp_buf state;
    int state_val = setjmp(state);
    if (state_val == STRING_FORMAT_ERROR ) {
        puts("String format error");
        exit(0);
    }
    char* str = "101";
    i32 str_to_int = s2i(str, 10, &state);
    print_i32(str_to_int);
    return 0;
}
