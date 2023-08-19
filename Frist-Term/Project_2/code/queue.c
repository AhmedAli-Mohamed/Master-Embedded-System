#include "queue.h"

int head, tail, counter;
int length = 50;
sinfo st[50];

                                                  /*------------Adding student----------------*/

void ADD_manually()
{
    // check if the queue is full
    if (counter == length)
    {
        printf("Queue is full");
    }
    else
    {
        int i;
        // scan student info
        printf("\nenter first name : ");
        scanf("%s", st[head].fname);
        printf("\nenter last name : ");
        scanf("%s", st[head].lname);
        l1:printf("\nenter roll number : ");

        // check if roll number is already exist
        scanf("%d", &(st[head].roll));
        for (i=0;i<counter;i++)
        {
            if (st[i].roll == st[head].roll && head!=tail)
            {
                printf("\n roll number is already exist");
                goto l1;
            }
        }

        printf("\nenter GPA : ");
        scanf("%f", &(st[head].gpa));
        for (i = 0; i < 5; i++)
        {
            printf("\n enter course %d : ", i+1);
            scanf("%d", &(st[head].cid[i]));
        }

        //increase counter and head 

        head = (head + 1) % length;
        counter++;
        
        //print additional information

        printf("\n\n[INFO]  student details is added successfully");
        printf("\n-------------------------");
        printf("\n[INFO]  the total number of student  is : %d",counter);
        printf("\n[INFO]  you can add upto %d student ",length);
        printf("\n[INFO]  you can add more %d students ",length-counter);
    }
}


void ADD_FROM_FILE()
{
    int i=0,j,temproll,k;
    char arr[10];
    char * temp;

    //make pointer to file and open the file
    FILE *fp ;
    fp = fopen("file.txt", "r");

    // scan student info
    while(i < file_size)
    {
        fscanf(fp, "%s", arr);
        temproll= atoi(arr);

        // check if roll number is already exist
        for (k=0;k<counter;k++)
        {
            if (st[k].roll == temproll && head!=tail)
            {
                while(fgetc(fp) != '\n');
                printf("\n[INFO]  ROLL number %d  is already exist",temproll);
                goto l2;
            }
        }

        st[head].roll= temproll;
        fscanf(fp, "%s", arr);
        strcpy(st[head].fname, arr);
        fscanf(fp, "%s", arr);
        strcpy(st[head].lname, arr);
        fscanf(fp, "%s", arr);
        st[head].gpa= atof(arr);
        for (j = 0; j < 5; j++)
        {
            fscanf(fp, "%s", arr);
            st[head].cid[j]= atoi(arr);
        }

        //print additional information
        printf("\n[INFO]  ROLL number %d  saved successfully",st[head].roll);
        printf("\n-------------------------");
        

        //increase counter and head 
        head = (head + 1) % length;
        counter++;
        l2:i++;

    } 
    printf("\n[INFO]  the total number of student  is : %d",counter);
    printf("\n[INFO]  you can add upto %d student ",length);
    printf("\n[INFO]  you can add more %d students ",length-counter);
    fclose(fp);

}

                                           /*------------searching on student----------------*/
//Find student Details by Roll Number                                           
int Find_byRoll()
{
    int roll_temp,i,j;
    printf("\nEnter roll number : ");
    scanf("%d",&roll_temp);
    for(i = 0; i< counter; i++)
    {
        if(roll_temp == st[i].roll)
        {
            printf("\n----------------------------------------");
            printf("\n\nstudent first name : %s", st[i].fname);
            printf("\n\nstudent last name : %s", st[i].lname);
            printf("\n\nstudent roll number : %d", st[i].roll);
            printf("\n\nstudent GPA number : %.2f", st[i].gpa);
            for (j = 0 ; j < 5 ; j++)
            {
                printf("\n\nthe course ID : %d",st[i].cid[j]);
            }
            return 1;

        }
    
    }
    printf("\n[ERROR]  Roll number not found");
    return 0;

}

//Find student Details by First Name
int Find_byFname()
{
    int i,j;
    char name_temp[20];
    printf("\nEnter First Nmae  : ");
    scanf("%s",name_temp);
    for(i = 0 ; i < counter ; i++)
    {
        if(strncmp(name_temp,st[i].fname,strlen(name_temp)) == 0)
        {
            printf("\n----------------------------------------");
            printf("\n\nstudent first name : %s", st[i].fname);
            printf("\n\nstudent last name : %s", st[i].lname);
            printf("\n\nstudent roll number : %d", st[i].roll);
            printf("\n\nstudent GPA number : %.2f", st[i].gpa);
            for (j = 0 ; j < 5 ; j++)
            {
                printf("\n\nthe course ID : %d",st[i].cid[j]);
            }
            return 1;
        }
        
        
    }
    printf("\n[ERROR]  First Name not found");
    return 0;

}

//Find student Details by Course ID
void Find_byCID()
{
    int cid_temp,i,j,flag=0;
    printf("\nEnter Course ID : ");
    scanf("%d",&cid_temp);
    for (i = 0 ; i < counter ; i++)
    {
        for(j = 0 ; j < 5 ; j++)
        {
            if(cid_temp == st[i].cid[j])
            {
            printf("\n----------------------------------------");
            printf("\n\nstudent first name : %s", st[i].fname);
            printf("\n\nstudent last name : %s", st[i].lname);
            printf("\n\nstudent roll number : %d", st[i].roll);
            printf("\n\nstudent GPA number : %.2f", st[i].gpa);

            flag =1;

            }
        }
    }

    if (flag == 0)
    {
        printf("\n[ERROR]  Course ID %d  not found",cid_temp);
    }



}

//Find the total number of students
void find_all()
{
    printf("\n[INFO]  the total number of student  is : %d",counter);
    printf("\n[INFO]  you can add upto %d student ",length);
    printf("\n[INFO]  you can add more %d students ",length-counter);

}


                                           /*------------Deleting a  student----------------*/


int Delete_byRoll()
{
    // check if queue is empty
    if(counter == 0)
    {
        printf("\n[ERROR] the queue is empty");
        return 0;
    }
    // scan roll number and compare against queue
    int roll_temp,i,j,temp,flag=0;
    printf("\nEnter roll number : ");
    scanf("%d",&roll_temp);
    for(i = tail; i< counter; i++)
    {
        if(roll_temp == st[i].roll)
        {
            temp = i ;
            flag = 1;
            break;

        }
    }

    // check if roll number exist in queue

    if(flag == 0)
    {
        printf("\n[ERROR] Roll number not found");
               return 0;
    }

    // deleting student
    for(i=1; i<= temp; i++)
    {
        st[i]=st[i-1];
    }

    // increment tail 
    tail = (tail + 1) % length;
    counter--;
    printf("\n[INFO] The Roll number is Removed successfully");

    return 1;

}

                                           /*------------Updating INFO---------------*/
 int update_info()
 {
    // check if queue is empty
    if(counter == 0)
    {
        printf("\n[ERROR] the queue is empty");
        return 0;
    }

    // scan roll number and compare against queue
    int roll_temp,i,j,temp,flag=0;
    int choice;
    printf("\nEnter roll number : ");
    scanf("%d",&roll_temp);
    for(i = tail; i< counter; i++)
    {
        if(roll_temp == st[i].roll)
        {
            temp = i ;
            flag = 1;
            break;

        }
    }

    // check if roll number exist in queue

    if(flag == 0)
    {
        printf("\n[ERROR] Roll number not found");
               return 0;
    }

    // update info
    printf("\n1: first name \n2: last name\n3: roll number\n4: GPA\n5: Courses");
    printf("\nEnter your choice  : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\nupdate first name : ");
        scanf("%s", st[temp].fname);
        printf("\n[INFO] Updated successfuly");
        break;

        case 2:
        printf("\nupdate last name : ");
        scanf("%s", st[temp].lname);
        printf("\n[INFO] Updated successfuly");
        break;

        case 3:
        printf("\nupdate roll number : ");
        scanf("%d", &(st[temp].roll));
        printf("\n[INFO] Updated successfuly");
        break;

        case 4:
        printf("\nupdate GPA : ");
        scanf("%f", &(st[temp].gpa));
        printf("\n[INFO] Updated successfuly");
        break;

        case 5:
        for (j = 0; j < 5; j++)
        {
            printf("\n enter course %d : ", j+1);
            scanf("%d", &(st[head].cid[j]));
        }
        printf("\n[INFO] Updated successfuly");
        break;

        default:
        printf("\n[ERROR] Invalid choice");
    }
    return 1;

 }                                          
void print_all_()
{
    int i,j;
    // check if the queue is empty
    if (head == tail)
    {
        printf("\n the queue is empty");
    }
    else
    {
        int tail1=tail;
        int head1=head;
        for (i = 0; i < counter; i++)
        {
            printf("\n----------------------------------------");
            printf("\n\nstudent first name : %s", st[tail1].fname);
            printf("\n\nstudent last name : %s", st[tail1].lname);
            printf("\n\nstudent roll number : %d", st[tail1].roll);
            printf("\n\nstudent GPA number : %.2f", st[tail1].gpa);
            for (j = 0 ; j < 5 ; j++)
            {
                printf("\n\nthe course ID : %d",st[tail1].cid[j]);
            }
            tail1 = (tail1 + 1)% length;
            
        }
    }
}
