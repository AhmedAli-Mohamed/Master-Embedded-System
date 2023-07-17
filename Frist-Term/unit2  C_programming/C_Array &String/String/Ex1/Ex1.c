#include <stdio.h>
void main()
{
    int i = 0, counter;
    char y, x[100];
    printf("Enter a string : ");
    gets(x);
    printf("Enter a character to find frequency : ");
    scanf("%c", &y);
    while (x[i] != 0)
    {
        if (x[i] == y)
        {
            counter++;
        }
        i++;
    }
    printf("\n frequecy of %c = %d", y, counter);
}
