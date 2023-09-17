#include "mystr.h"

size_t my_strlen (const char* str) {
    // assert(!str);
    if (!str) {
        puts ("String is null");
        return 0;
    }
    size_t pos = 0;
    while (str[pos]) pos++ ;
    return pos;
}

void my_strcpy(char* dest, const char* source) {
    if (!dest || !source) {
        puts ("One of the strings is null");
        return;
    }
    size_t i = 0;
    for (; i < my_strlen(source); i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
}

char* my_strcat (char* destination, const char* append) {
    assert(destination && append);
    size_t dest_len = my_strlen(destination);  
    size_t app_len = my_strlen(destination);  
    for (size_t i = 0; i < app_len; i++) {
        destination[dest_len + i] = append[i];
    }
    return destination;
}
