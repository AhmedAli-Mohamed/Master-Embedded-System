#include<stdio.h>
void main()
{
    int x;
    printf("Enter a number : ");
    scanf("%d",&x);
    if(x>0)
    {
        printf("%d is positive",x);
    }
    else if (x<0)
    {
        printf(" %d is negative",x);
    }
    else
    {
        printf("you entered zero",x);
    }
}