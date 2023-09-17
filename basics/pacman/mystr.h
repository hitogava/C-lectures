#ifndef MYSTR_H
#define MYSTR_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


size_t my_strlen (const char* str);
char* my_strcat (char* destination, const char* append);
void my_strcpy (char* to, const char* from);
#endif
