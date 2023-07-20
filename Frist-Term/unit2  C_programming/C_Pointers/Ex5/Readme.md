# Ex5 :
### Write a program in C to show a pointer to an array which contents are pointer to structure.

# solution :
```c
#include <stdio.h>

struct Exmployee
{
    char Name[100];
    int ID;
};
void main()
{
    struct Exmployee e1 = {"ahmed", 50}, e2 = {"samir", 55}, e3 = {"adel", 66};
    struct Exmployee *arr[] = {&e1, &e2, &e3};
    struct Exmployee *(*ptr)[3] = &arr;

    /*to print e2*/
    printf("Exmployee Name : %s\n", ((*ptr)[1])->Name);
    printf("Exmployee ID : %d\n", ((*ptr)[1])->ID);
}
```