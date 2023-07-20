#include <stdio.h>
void main()
{
    int m = 29, *ab;
    printf(" Address of m: %d\n value of m : %d", &m, m);
    printf("\nNow ab is assigned with the address of m.");
    ab = &m;
    printf("\nAddress of pointer ab : %d\n Content of pointer ab : %d", ab, *ab);
    printf("\nThe value of m assigned to 34 now.");
    *ab = 34;
    printf("\nAddress of pointer ab : %d\n Content of pointer ab : %d", ab, *ab);
    printf("\nThe pointer variable ab is assigned with thevalue 7 now.");
    *ab = 7;
    printf("\nAddress of pointer m : %d\n Content of pointer m : %d", ab, *ab);
}