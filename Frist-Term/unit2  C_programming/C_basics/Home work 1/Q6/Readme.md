# Ex6:
Write Source Code to Swap Two Numbers

#########Console_output######

Enter value of a: 1.20

Enter value of b: 2.45

After swapping, value of a = 2.45

After swapping, value of b = 1.2

# Solution

```c
#include <stdio.h>
void main()
#include <stdio.h>
void main()
{
    float a, b, temp;
    printf("Enter value of a :");
    scanf("%f", &a);
    printf("Enter value of b :");
    scanf("%f", &b);
    temp = a;
    a=b;
    b= temp;
    printf("After swapping a=%.2f \nAfter swapping b=%.2f", a, b);

}
```