#include <stdio.h>
#include <string.h>

void rev(char sen[], int x);

void main()
{

    char sen[100];
    printf("Enter a sentence : ");
    gets(sen);
    rev(sen, strlen(sen));
}

/*function to reversed sentense*/

void rev(char sen[], int x)
{
    int i;
    for (i = x - 1; i >= 0; i--)
    {
        printf("%c", sen[i]);
    }
}