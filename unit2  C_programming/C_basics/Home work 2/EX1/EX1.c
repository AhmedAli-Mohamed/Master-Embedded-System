#include<stdio.h>
void main()
{
    int x;
    printf("Enter integer you want to check : ");
    scanf("%d",&x);
    if(x%2==0)
    {
        printf("%d is even",x);
    }
    else
    {
        printf(" %d is odd",x);
    }
}