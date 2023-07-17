#include <stdio.h>
void prime(int start, int end);
void main()
{
    int start, end;
    scanf("%d%d", &start, &end);
    prime(start, end);
}
void prime(int start, int end)
{
    int i, j, flag = 0, size = 0, res[100] = {0};
    for (i = start; i <= end; i++)
    {
        flag = 0;
        if (i == 0 || i == 1)
        {
            i = 2;
        }
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            res[size] = i;
            size++;
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d\n", res[i]);
    }
}