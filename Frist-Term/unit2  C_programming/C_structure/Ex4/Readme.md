# Ex4:
### scan array of struct students and print it
# solution :
```c
#include <stdio.h>
struct student
{
    char name[20];
    int rollno;
    float marks;
};
void main()
{
    int i, count = 0;
    struct student s[10];
    printf("Enter information of student : \n");
    do
    {
        fflush(stdin);
        printf("Enter name : ");
        gets(s[count].name);
        printf("Enter rollno : ");
        scanf("%d", &s[count].rollno);
        printf("Enter marks : ");
        scanf("%f", &s[count].marks);
        printf("Enter another information (y/n): ");
        count++;
        fflush(stdin);
    } while (getchar() == 'y' || getchar() == 'Y');

    printf("\n\n Display information");

    for (i = 0; i<count; i++)
    {
        printf("\nRollno : %d", s[i].rollno);
        printf("\nName : %s", s[i].name);
        printf("\nMarks : %f", s[i].marks);
        printf("\n");
    }
    
}
```