# EX1 :
### function to display prime numbers between two numbers scaned from user

# solution:
```c
#include <stdio.h>
#include"prime.h"
void main()
{
    int start,end;
    printf("Enter two numbers(interval) :");
    scanf("%d%d",&start,&end);
    prime(start,end);
}


/* function take 2 numbers and print prime numbers between them*/

void prime(int start, int end)
{
    int i, j, k = 0, flag, res[100];

    for (i = start; i <= end; i++)
    {
        flag = 0;
        if (start == 0 || start == 1)
        {
            continue;
        }
        for (j = 2; j <= i / 2; j++)
        {
            if (i == 2)
                break;

            else if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            res[k] = i;
            k++;
        }
    }
    printf("prime numbers betwwen %d and %d are : ", start, end);

    for (i = 0; i < k; i++)
    {
        printf("%d  ", res[i]);
    }
}
```