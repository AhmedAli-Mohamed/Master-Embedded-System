#include<stdio.h>
#include<math.h>
int reversed(int x);
void main()
{
  int x;
  scanf("%d",&x);
  printf("%d\n",reversed(x));
}

int reversed(int x)
{
    int rev=0;
    while(x!=0)
    {
        rev=rev*10+x%10;
        x/=10;
    }
    return rev;
}