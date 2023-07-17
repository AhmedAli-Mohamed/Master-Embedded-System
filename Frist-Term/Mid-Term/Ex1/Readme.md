# Ex1 :
### c function to take a number and sum all digits? 

# solution :
```c
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
```