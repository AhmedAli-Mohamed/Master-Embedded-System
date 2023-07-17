# Ex2 :
### program to calculate factorial

# solution :
```c
#include<stdio.h>

int fact(int num);


void main()
{
   int num;
   printf("Enter a poditive integer: ");
   scanf("%d",&num);
   printf("Factorial of %d =  %d\n",num,fact(num));

}



/*Recursive function to calculate factorial*/

int fact(int num)
{
    int ret_val;
    if(num==1 || num==0)
        ret_val = 1;
    else
        ret_val= num*fact(num-1);
        return ret_val;
}
```