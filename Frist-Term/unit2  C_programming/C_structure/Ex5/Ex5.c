#include <stdio.h>
#define Area(r) 3.14 * r *r

void main()
{
    float radius;
    float area;
    printf("Enter radius : ");
    scanf("%f", &radius);
    area = Area(radius);
    printf("Area of circle is %.2f", area);
}