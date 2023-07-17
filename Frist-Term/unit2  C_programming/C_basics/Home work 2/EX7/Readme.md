# EX7 :
### program to calculate the factorial

# Solution

```c
#include<stdio.h>
void main()
{
    int x,i,sum=1;
    printf("Enter an integer : ");
    scanf("%d",&x);
    if(x<0)
    {
        printf("Error !! Factorial of negative number doesnot exist");
    }
    else if (x==0 || x==1)
    {
        printf(" Factorial = 1");
    }
    else
    {
        for(i=1;i<=x;i++)
        {
            sum=sum*i;
        }
        printf("Factorial = %d",sum);
    }
}
```