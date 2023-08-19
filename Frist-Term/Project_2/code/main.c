#include "queue.h"

void main()
{
      int choice = 0;
    
    while(1)
    {
        system("cls");
        printf("--------CATOGEERIES--------\n");
        printf("1: Add a student Dtails Manually \n2: Add a student Dtails from text file  \n3: Find student Details by Roll Number \n4: Find student Details by First Name");
        printf("\n5: Find student Details by Course ID \n6: Find the total number of students\n7:Delete the student Details by Roll number \n8: Update the student Details by Roll number");
        printf("\n9: Show all students\n10: Exit");
        printf("\n\nenter your choice : ");
        scanf("%d",&choice);

        switch (choice)
    {
        case 1:
        system("cls");
        ADD_manually();
        break;

        case 2:
        system("cls");
        ADD_FROM_FILE();
        break;

        case 3:
        system("cls");
        Find_byRoll();
        break;

        case 4:
        system("cls");
        Find_byFname();
        break;

        case 5:
        system("cls");
        Find_byCID();
        break;

        case 6:
         system("cls");
         find_all();
         break;

         case 7:
         system("cls");
         Delete_byRoll();
         break;

         case 8:
         system("cls");
         update_info();
         break;

        case 9:
        system("cls");
        print_all_();
        break;

        case 10:
        exit(0);

    }
       printf("\n\nDo another operation (y/n): ");
        fflush(stdin);
        if(getchar() == 'y' || getchar() == 'Y')
        {
            continue;
        }
       
        else 
        {
            break;
        }
    }

}
      