#include<stdio.h>
struct distance
{
    int feet;
    double inches;
}d1,d2,sum;
void main()
{
    printf("Enter information of 1st distance\n");
    printf("Enter feet : ");
    scanf("%d",&d1.feet);
    printf("Enter inches : ");
    scanf("%lf",&d1.inches);
    printf("Enter information of 2nd distance\n");
    printf("Enter feet : ");
    scanf("%d",&d2.feet);
    printf("Enter inches : ");
    scanf("%lf",&d2.inches);
    sum.feet=d1.feet+d2.feet;
    sum.inches=d1.inches+d2.inches;
   while(sum.inches>=12)
   {
    sum.inches-=12;
    sum.feet++;
   }
    printf("sum of distance : %d.%.0lf  feet",sum.feet,sum.inches);

}