# Ex2 :
### c function to take an integer number and calculate it's square root?

# solution :
```c
#include<stdio.h>
#include<math.h>
double squareroot(double x)
{
    return sqrt(x);

}

int main()
{
    double x;
    scanf("%lf",&x);
    printf("%.2lf",squareroot(x));
    return 0;
}
```