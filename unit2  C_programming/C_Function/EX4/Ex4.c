#include <stdio.h>

int power_fun(int base, int power);

void main()
{
    int num, power;
    printf("Enter base number : ");
    scanf("%d", &num);
    printf("\nEnter power number : ");
    scanf("%d", &power);
    printf("%d^%d= %d", num, power, power_fun(num, power));
}

/* Recursiver function to return power of base number*/

int power_fun(int base, int power)
{
    int ret_val;
    if (power == 0)
    {
        ret_val = 1;
    }
    else if (power == 1)
    {
        ret_val = base;
    }
    else
    {
        ret_val = base * power_fun(base, power - 1);
    }
    return ret_val;
}