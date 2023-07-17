#include<stdio.h>

void rev(int num[], int x);

void main()
{

    int i, x,num[100];
    printf("Enter a size : ");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&num[i]);
    }
    rev(num, x);
}

/*function to reversed array*/

void rev(int num[], int x)
{
    int i;
    for (i = x - 1; i >= 0; i--)
    {
        printf("%d ", num[i]);
    }
}