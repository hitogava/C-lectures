#include <inttypes.h>
#include <math.h>
#include <setjmp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t i32;
typedef uint32_t ui32;

#define STRING_FORMAT_ERROR 1
#define STRING_BASE_ERROR 2
#define STRING_NAD_ERROR 3 // Not a digit

#define try if (!state_val)
#define catch(error) if (state_val == error)
#define catch_other if (state_val)

#define print_i32(n) printf("%" PRId32 "\n", n)

/**
 * Magic number for convert 16 (or greater) base (A,B,...F) symbols into integer
 * representation E.g: A (65 in ASCII) - HEX_MAGIC_NUMBER = 10
 */
#define HEX_MAGIC_NUMBER 55

/**
 * If char contains non digit or letter of numeral system -> false else -> true
 */
bool is_char_good(char ch, ui32* digit) {
    if ('0' <= ch && ch <= '9') {
        *digit = (ch - '0');
        return true;
    } else if ('A' <= ch && ch <= 'F') { // boundaries are hardcoded
        *digit = ch - HEX_MAGIC_NUMBER;
        return true;
    }
    return false;
}

ui32 ensure_format(char ch, ui32 base, jmp_buf* state) {
    ui32 digit;
    bool isgood = is_char_good(ch, &digit);
    if (isgood && digit < base) {
        return digit;
    } else if (!isgood) {
        longjmp(*state, STRING_NAD_ERROR);
    } else if (digit >= base) {
        longjmp(*state, STRING_BASE_ERROR);
    } else {
        longjmp(*state, STRING_FORMAT_ERROR);
    }
}

i32 s2i(const char* string, ui32 base, jmp_buf* state) {
    if (base > 16) {
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
        if (i == 0 && ch == '-') {
            continue;
        }
        ui32 digit = ensure_format(ch, base, state);
        result += digit * (i32)(pow(base, power++));
    }
    result *= sign;
    return result;
}

void example() {
    jmp_buf state;
    int state_val = setjmp(state);
    try {
        char* str = "-101010";
        i32 str_to_int = s2i(str, 2, &state);
        print_i32(str_to_int);
    } catch (STRING_BASE_ERROR) {
        puts("String contains digits that not fit base of numberical system");
        exit(0);
    } catch (STRING_NAD_ERROR) {
        puts("String contains non digintal characters");
        exit(0);
    }
    catch_other {
        puts("Something went wrong");
        exit(0);
    }
}

int main() {
    example();
    return 0;
}
