# Ex3 :
### Write a program in C to print a string in reverse using a pointer

# solution :
```c
#include <stdio.h>
#include <string.h>

void reversed(char str[], int len);
void main()
{
    char str[100];
    gets(str);
    reversed(str, strlen(str));
}

void reversed(char str[], int len)
{
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}
```