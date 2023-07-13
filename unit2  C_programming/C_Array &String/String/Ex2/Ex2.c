#include <stdio.h>
void main()
{
    int counter = 0;
    char x[100];
    printf("Enter the string: ");
    gets(x);
    while (x[counter] != 0)
    {
        counter++;
    }
    printf("The length of the string is %d", counter);
}
