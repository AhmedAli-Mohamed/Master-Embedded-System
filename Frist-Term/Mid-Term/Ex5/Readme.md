# Ex5:
### c function to count number of ones in binary number?

# solution :
```c
#include<stdio.h>
int binary(int x);
void main()
{
    int x;
    scanf("%d", &x);
    printf("%d",binary(x));
}

int binary(int x)
{
    unsigned int i,sum=0;
    for(i=0;i<32;i++)
    {
        if ((x&1<<i)>>i ==1)
        {
            sum++;
        }
    }
    return sum;
}
```