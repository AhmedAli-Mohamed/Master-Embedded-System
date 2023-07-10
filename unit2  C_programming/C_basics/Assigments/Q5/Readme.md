# Ex5 :
Write C Program to Find ASCII Value of a Character

#########Console_output######

Enter a character: G

ASCII value of G = 71

# Solution

```c
#include <stdio.h>
void main()
{
    char x;
     printf("Enter a character : ");
    scanf("%c", &x);
    printf("ASCII value of %c is : %d",x,x);
}

```