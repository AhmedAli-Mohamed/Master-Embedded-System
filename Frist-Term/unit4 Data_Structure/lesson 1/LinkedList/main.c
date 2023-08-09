#include<stdio.h>
#include"types.h"
#include"student.h"
#include<string.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
    int choice = 0,index;
    
    while(1)
    {
        system("cls");
        printf("--------CATOGEERIES--------\n");
        printf("1: Adding a new student \n2: Searching for students \n3: Deleting student Data \n4: Additional Features");
        printf("\n\nenter your choice : ");
        scanf("%d",&choice);

        switch (choice)
    {
        case 1:
        system("cls");
        AddStudent();
        break;

        case 2:
        system("cls");
        printf("---------Searching for students-------\n");
        printf("1: Search by ID \n2: Search bu index \n3: Print All Students\n\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            SEARCH_by_ID();                      break;
            case 2:
            SEARCH_by_index();                   break;
            case 3:
            print_list();                        break; 
        }

        printf("Do another operation (y/n): ");
        fflush(stdin);
        if(getchar() == 'y' || getchar() == 'Y')
        {
             break;

        }
       
        else 
        {
            goto L1 ;
        }
        case 3:
        system("cls");
        printf("---------Removing a  student-------\n");
        printf("1: Remove by ID \n2: Remove bu index \n3: Remove All Students");
        printf("\n\nenter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            REMOVE_by_ID();                      break;
            case 2:
            REMOVE_by_index();                   break;
            case 3:
            REMOVE_all();                        break; 
        }

        printf("Do another operation (y/n): ");
        fflush(stdin);
        if(getchar() == 'y' || getchar() == 'Y')
        {
             break;

        }
       
        else 
        {
            goto L1 ;
        }
        case 4:
         system("cls");
        printf("---------Additional Features-------\n");
        printf("1: Print Middle \n2: Print Reversed index \n3: Sort All Students by height\n4: Reverse all students");
        printf("\n\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            PRINT_MIDDLE();                    break;
            case 2:
            PRINT_REV_INDEX();                 break;
            case 3:
            SORT_LIST ();                    break;
            case 4:
            REVERSE_LIST ();                        break;

        }
        printf("Do another operation (y/n): ");
        fflush(stdin);
        if(getchar() == 'y' || getchar() == 'Y')
        {
             break;

        }
       
        else 
        {
            goto L1 ;
        }
        
    
    }

    }
    L1 : printf ("----------thanks ---------");
    
}
