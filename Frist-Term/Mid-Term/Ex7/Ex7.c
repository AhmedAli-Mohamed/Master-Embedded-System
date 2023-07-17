#include<stdio.h>
void main()
{
    int i=0,j, sum=0;
    printf("Enter number between 1 and 100 : ");
    scanf("%d",&j);
    L1:
    if (i<=j)
    {
        sum=sum+i;
        i++;
        goto L1;
    }
    printf("%d",sum);
}