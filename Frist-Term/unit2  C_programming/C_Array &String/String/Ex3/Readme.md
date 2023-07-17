# Ex3 :
### program to scan string from user and return reversed string

# solution :
```c
#include <stdio.h>
void main()
{
    int i, counter = 0;
    char x[100];
    printf("Enter the string: ");
    gets(x);
    while (x[counter] != 0)
    {
        counter++;
    }
    printf("Reverse string is : ");

    for (i = counter; i >= 0; i--)
    {
        printf("%c", x[i]);
    }
}

```