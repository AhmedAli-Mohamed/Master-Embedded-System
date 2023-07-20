# Ex2 :
### Write a program in C to print all the alphabets using a pointer.

# solution :
```c
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
```