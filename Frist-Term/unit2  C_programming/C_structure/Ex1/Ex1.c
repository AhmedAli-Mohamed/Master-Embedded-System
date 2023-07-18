#include <stdio.h>
struct student
{
    char name[20];
    int rollno;
    float marks;
};
void main()
{
    struct student s;

    printf("Enter information of student : \n");
    printf("Enter name : ");
    gets(s.name);
    printf("Enter rollno : ");
    scanf("%d", &s.rollno);
    printf("Enter marks : ");
    scanf("%d", &s.marks);
    printf("\n\n Display information");
    printf("\nName : %s", s.name);
    printf("\nRollno : %d", s.rollno);
    printf("\nMarks : %f", s.marks);
}