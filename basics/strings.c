#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_BUFFER_LENGTH 100

#define VEC_INIT_CAPACITY 8

void alloc_guard(void* ptr) {
    if(!ptr) {
        printf("Allocation error occured in %s on line %d\n", __FILE__, __LINE__);
        exit(0);
    } 
}
typedef struct string_vec {
    size_t length;
    size_t capacity;
    char** data;
} string_vec;
void string_vec_init(string_vec* vec) {
    if (!vec) { return; }
    vec->length = 0;
    vec->capacity = VEC_INIT_CAPACITY;
    vec->data = malloc(vec->capacity * sizeof(char*));
    alloc_guard(vec->data);
}
void ensure_capacity(string_vec* self) {
    if (!self) { return; }
    if (self->length >= self->capacity) {
        size_t new_capacity = self->capacity + self->length;
        self->data = realloc(self->data, new_capacity * sizeof(char*));
        alloc_guard(self->data);
        self->capacity = new_capacity;
    }
}
void string_vec_push_back(string_vec* self, const char* str) {
    ensure_capacity(self);
    size_t str_len = strlen(str);
    // extra byte for '\0'
    self->data[self->length] = malloc(str_len + 1);
    alloc_guard(&self->data[self->length]);
    strcpy(self->data[self->length],str);
    self->data[self->length][str_len] = '\0';
    self->length++;
}
void string_vec_drop(string_vec* self) {
    for (size_t i = 0; i < self->length; i++) {
        free(self->data[i]);
    }
    free(self->data);
    self->length = 0;
    free(self);
}
bool palindrome(const char str[]) {
    size_t i = 0;
    size_t j = strlen(str)-1;
    while (i != j) {
        if (str[i] == ' ') {
            i++;
            continue;
        } 
        if (str[j] == ' ') {
            j--;
            continue;
        }
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}
void test_palindrome() {
    assert(palindrome("a") == 1);
    assert(palindrome("ahh") == 0);
    assert(palindrome("ah") == 0);
    assert(palindrome("sfsfsaf") == 0);
    assert(palindrome("hah") == 1);
    assert(palindrome("aaa") == 1);
    assert(palindrome("a b a") == 1);
    assert(palindrome("ab a") == 1);
    assert(palindrome("    aba    ") == 1);
    assert(palindrome("  ab a") == 1);
    assert(palindrome("str r ts") == 1);
    assert(palindrome("boaob") == 1);
}
char* trim(const char* source) {
    size_t i = 0;
    size_t source_size = strlen(source);
    size_t j = source_size - 1;
    while (source[i] == ' ') i++;
    // If source string contains only spaces or empty - return empty string
    if (i > j || source_size == 0) {
        char* trimmed = malloc(sizeof(char));
        alloc_guard(trimmed);
        trimmed[0] = '\0';
        return trimmed;
    }
    while (source[j] == ' ') j--;
    size_t trimmed_size = j - i + 1;
    char* trimmed = malloc(trimmed_size + 1);
    alloc_guard(trimmed);
    strncpy(trimmed, source + i, trimmed_size);
    trimmed[trimmed_size] = '\0';
    return trimmed;
}
string_vec* split(const char* str) {
    string_vec* vec = malloc(sizeof(string_vec));
    alloc_guard(vec);
    string_vec_init(vec);
    const char* trimmed = trim(str);
    size_t trimmed_len = strlen(trimmed);
    char buffer[MAX_BUFFER_LENGTH];
    size_t buf_ind = 0;
    for (size_t i = 0; i < trimmed_len; i++) {
        if (trimmed[i] != ' ') {
            buffer[buf_ind++] = trimmed[i];
        }
        if ((i+1) == trimmed_len || trimmed[i] == ' ') {
            buffer[buf_ind] = '\0';
            if(buf_ind)
                string_vec_push_back(vec, buffer);
            buf_ind = 0;
        }
    }
    free((char*)trimmed);
    return vec;
}
int main() {
    return 0;
}
