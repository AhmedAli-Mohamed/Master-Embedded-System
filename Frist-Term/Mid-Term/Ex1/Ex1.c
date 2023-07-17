#include<stdio.h>
void main()
{
    int num,sum=0;
    scanf("%d",&num);
    do{
        sum+=num%10;
        num=num/10;
    }while (num!=0);
    printf("%d",sum);
    
    
}