# Ex3 :
Write C Program to Add Two Integers

i should see the Console as following:

##########Console-output###

Enter two integers: 12
11

Sum: 23

# Solution

```c
#include <stdio.h>
void main()
{
    int x,y;
    printf("Enter two integers: ");
    scanf("%d%d",&x,&y);
    printf("sum: %d",x+y);
}

```