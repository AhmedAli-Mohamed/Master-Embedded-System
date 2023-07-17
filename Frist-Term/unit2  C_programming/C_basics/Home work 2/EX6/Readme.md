# EX6 :
### program to display sum of all integers from 1 to n

# Solution

```c
#include<stdio.h>
void main()
{
    int x,i,sum=0;
    printf("Entet an integer :");
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        sum=sum+i;
    }
    printf("%d",sum);
}
```