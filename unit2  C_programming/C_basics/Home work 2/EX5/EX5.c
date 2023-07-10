#include <stdio.h>
void main()
{
    char x;
    printf("Enter a character : ");
    scanf("%c", &x);
    switch (x)
    {
    case 'a' ... 'z':
    case 'A' ... 'Z':
        printf("%c is an alphabet", x);

        break;

    default:
        printf("%c is not an alphabet", x);
        break;
    }
}