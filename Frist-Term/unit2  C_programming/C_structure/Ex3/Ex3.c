#include <stdio.h>
struct complex
{
    float real;
    float imag;
};

/*function to sum 2 struct complex*/

struct complex sum(struct complex x, struct complex y)
{
    struct complex z;
    z.real = x.real + y.real;
    z.imag = x.imag + y.imag;
    return z;
}
void main()
{
    struct complex a, b, c;
    printf("for 1st complex number\n");
    printf("enter real and imaginary respectively : ");
    scanf("%f %f", &a.real, &a.imag);
    printf("for 2nd complex number\n");
    printf("enter real and imaginary respectively : ");
    scanf("%f%f", &b.real, &b.imag);
    c = sum(a, b);
    c.imag > 0 ? printf("sum = %.1f+%.1f i", c.real, c.imag) : printf("sum = %.1f %.1f i", c.real, c.imag);
}
