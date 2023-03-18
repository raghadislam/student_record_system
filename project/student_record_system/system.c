
#include <stdio.h>
#include "system.h"

size_t my_strlen(const char *s)
{
    const char *p = s;
    while(*s)
        s++;
        return s-p;
}


char *my_strcpy(char *s1, const char *s2)
{
    while(*s1++ = *s2++);
    return s1;
}
