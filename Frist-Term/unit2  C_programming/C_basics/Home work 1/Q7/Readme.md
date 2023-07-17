# Ex7 :

Write Source Code to Swap Two Numbers without temp variable.


# Solution

```c
#include <stdio.h>
void main()
{
    float a,b;
  printf("Enter value of a :");
    scanf("%f", &a);
    printf("Enter value of b :");
    scanf("%f", &b);
    b=a+b;
    a=b-a;
    b=b-a;
    printf("After swapping a=%.2f \nAfter swapping b=%.2f", a, b);

}

```