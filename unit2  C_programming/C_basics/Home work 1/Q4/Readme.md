# Ex4 :
Write C Program to Multiply two Floating Point Numbers

i should see the Console as following:

##########Console-output###

###########################

Enter two numbers: 2.4
1.1

Product: 2.640000

# Solution

```c
#include <stdio.h>
void main()
{
    float x,y;
    printf("Enter two integers: ");
    scanf("%f%f",&x,&y);
    printf("product: %.2f",x*y);
}

```