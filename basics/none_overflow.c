#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define BUFF_SIZE 32

size_t readstr (char* buf) {
    size_t pos = 0;
    char c;
    while ((c = getchar()) && c != EOF && c != '\n') {
        buf[pos++] = c;
    }
    return pos;
}

bool is_int (char* buf) {
    assert(buf);
    for (size_t i = 0; buf[i]; i++) {
        if (!(isdigit(buf[i]) || (buf[i] == ('-') && i == 0))) {
            return false;
        }
    }
    return true;
}

size_t str_len (char* buf) {
    size_t pos = 0;
    while (buf[pos]) pos++;
    return pos;
}

void int_to_str (char* buf, int value) {
    size_t pos = 0;
    if (value < 0) {
        buf[pos++] = '-';
    }
    do {
        buf[pos++] = abs(value % 10) + '0';
        value = abs(value / 10);
    }
    while (value > 0);
    buf[pos] = '\0';
}

bool is_negative (char* str) {
    assert(str);
    return str[0] == '-';
}

// Returns minimal int (as string)
char* str_comp_as_ints (char *str1, char* str2) {
    assert(str1 && str2);
    if (is_negative(str1) && is_negative(str2)) {
        // puts ("negatives");
        size_t len1 = str_len(str1);
        size_t len2 = str_len(str2);
        if (len1 != len2) {
            return (len1 < len2) ? str2 : str1;
        }
        assert(len1 == len2 && str1[0] == '-');
        for (size_t i = 1; i < len1; i++) {
            if (str1[i] > str2[i])
                return str1;
            else if (str1[i] < str2[i])
                return str2;
        }
    }
    return NULL;
}

void safe_read_int (char* buf, int* value) {
    char int_max_buf [BUFF_SIZE];
    char int_min_buf [BUFF_SIZE];
    int_to_str(int_max_buf, INT_MAX);

    if (is_int(buf)) {
    } else {
        puts ("Entered value is not an integer type");
        exit(0);
    }
}

int main (int argc, char** argv) {
    char buf [BUFF_SIZE];
    // if (readstr(buf) > 0) {
    //     safe_read_int(buf, NULL);
    // }
    char* test = str_comp_as_ints("-1", "-12");
    printf("%s\n", test);
    test = str_comp_as_ints("-1", "-2");
    printf("%s\n", test);
    int_to_str(buf, INT_MIN);
    // test = str_comp_as_ints("-1", buf);
    // printf("%s\n", test);
    int_to_str(buf, 23456);
    printf("%s\n", buf);
    return 0;
}
