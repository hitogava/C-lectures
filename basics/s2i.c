#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>

typedef int32_t i32;
typedef uint32_t ui32;

#define STRING_FORMAT_ERROR 1
#define STRING_BASE_ERROR 2
#define NAD 3 // Not a digit
#define print_i32(n) printf("%" PRId32 "\n",n)

/**
 * Magic number for convert 16 (or greater) base (A,B,...F) symbols into integer representation
 * E.g: A (65 in ASCII) - HEX_MAGIC_NUMBER = 10
 */
#define HEX_MAGIC_NUMBER 55

/**
 * If char contains non digit or letter of numeral system -> false else -> true
 */
bool is_char_good(char ch, ui32* digit) {
    if('0' <= ch && ch <= '9') {
        *digit = (ch - '0');
        return true;
    } else if('A' <= ch && ch <= 'F') { // boundaries are hardcoded
        *digit = ch - HEX_MAGIC_NUMBER;
        return true;
    }
    return false;
}

ui32 ensure_format(char ch, ui32 base, jmp_buf* state) {
    ui32 digit;
    bool is_good = is_char_good(ch, &digit);
    if (is_good && digit < base) {
        return digit;
    }
    longjmp(*state, STRING_FORMAT_ERROR);
}

i32 s2i(const char* string, ui32 base, jmp_buf* state) {
    if(base > 16) {
        puts("Maximum base is 16");
        exit(0);
    }
    i32 result = 0;
    ui32 power = 0;
    size_t string_len = strlen(string);
    // 1 -> positive, -1 -> negative
    ui32 sign = string_len > 0 && string[0] == '-' ? -1 : 1;
    for (int i = string_len - 1; i >= 0; i--) {
        char ch = string[i];
        if (i == 0 && ch == '-') { continue; }
        ui32 digit = ensure_format(ch, base, state);
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
    char* str = "123";
    i32 str_to_int = s2i(str, 3, &state);
    print_i32(str_to_int);
    return 0;
}
