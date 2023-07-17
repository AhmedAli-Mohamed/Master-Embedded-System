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
