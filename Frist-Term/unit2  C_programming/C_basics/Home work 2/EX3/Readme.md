# EX3 :
### program to determine the largest number of three numbers


# Solution

```c
#include <stdio.h>
void main()
{
    float x,y,z;
    printf("Enter three numbers: ");
    scanf("%f%f%f",&x,&y,&z);
    if (x>y)
    {
        if (x>z)
        {
            printf("The largest number is %f\n",x);
        }
        else
        {
            printf("The largest number is %f\n",z);
        }
    }
    else
    {
        if (y>z)
        {
            printf("The largest number is %f\n",y);
        }
        else
        {
            printf("The largest number is %f\n",z);
        }
    }
}
```
