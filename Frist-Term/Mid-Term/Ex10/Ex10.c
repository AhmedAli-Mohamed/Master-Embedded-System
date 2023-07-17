#include <stdio.h>
int num_of_ones(int x);
void main()
{
    int num;
    scanf("%d",&num);
    printf("\n%d",num_of_ones(num));
}

int num_of_ones(int x)
{
    int i,sum=0,res=0;
    for(i=0;i<32;i++)
    {
        if((x&1<<i)>>i==1)
        {
            sum++;
        }
        else
        {
            if (sum>res)
            {
                res=sum;
            }
            sum=0;
        }
    }
    return res;
    }
    
