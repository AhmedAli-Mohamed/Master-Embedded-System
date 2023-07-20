#include <stdio.h>
void main()
{
    char *ptr, c;
    ptr = &c;
    *ptr = 'A';

    while (*ptr != 'Z' + 1)
    {
        printf("%c ", *ptr);
        (*ptr)++;
    }
}