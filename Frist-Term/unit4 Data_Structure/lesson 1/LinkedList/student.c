#include<stdio.h>
#include"types.h"
#include"student.h"
#include<string.h>
#include<stdlib.h>

student * HEAD=NULL;
uint32 counter=0;
//--------------------Adding a new student------------------------
void AddStudent()
{
    student * newstudent;
    student * laststudent;

    //check if list is empty
    if(HEAD==NULL)
    {
        newstudent=(student *) malloc(sizeof(student));
        HEAD=newstudent;
    }

    else
    {
        laststudent=HEAD;
        while (laststudent->next!=NULL)
        {
            laststudent=laststudent->next;
        }
        newstudent=(student *) malloc(sizeof(student));
        laststudent->next=newstudent;
    }

    // set new node to null
    newstudent->next=NULL;

    // fill data
    fill_data(newstudent);

    //increment counter
    counter++;

}


//------------------------------------- PRINT STUDENT INFO ----------------------------------------

int SEARCH_by_ID()
{
    //scan id
    uint32 id;
    student * currentstudent=HEAD;
    printf("enter student ID: ");
    scanf("%d",&id);

//loop to find id
    while(currentstudent != NULL)
    {
        if(currentstudent->data.ID == id)
        {
            printf("\n=======================\n");
       // printf("\nrecord number: %d",);
        printf("\nstudent ID: %d",currentstudent->data.ID);
        printf("\nstudent name:  %s",currentstudent->data.name);
        printf("\nstudent height: %.2f",currentstudent->data.height);
        printf("\n=======================\n");
        return 1;
        }
        currentstudent = currentstudent->next;
    }
    // id not found
    printf("invalid index");
    return 0;  

}
int SEARCH_by_index()
{
    //scan index
    uint32 index;
    printf("enter student index: ");
    scanf("%d",&index);
    
    uint32 i;
    student * currentstudent=HEAD;

    // check index
    if (index <1)
    {
        printf("invalid index");
        return 0;
    }
    else
    {
        for(i=1;i<index;i++)
        {
            // check if index more than list
            if(currentstudent != NULL)
            currentstudent =currentstudent->next;

            else
            {
                printf("invalid index");
                printf("\n=======================\n");
                 return 0;
            }
        }
        printf("\n=======================\n");
        printf("\nrecord number: %d",i);
        printf("\nstudent ID: %d",currentstudent->data.ID);
        printf("\nstudent name:  %s",currentstudent->data.name);
        printf("\nstudent height: %.2f",currentstudent->data.height);
        printf("\n=======================\n");
        return 1;
        

    }
    
}
int print_list()
{
    student * currentstudent=HEAD;
    uint32 i;
    if(HEAD ==NULL)
    {
        printf("\nlist is empty");
        printf("\n=======================\n");
        return 1;

    }
    for(i=1;i<=counter;i++)
    {
        printf("\nrecord number: %d",i);
        printf("\nstudent ID: %d",currentstudent->data.ID);
        printf("\nstudent name:  %s",currentstudent->data.name);
        printf("\nstudent height: %.2f",currentstudent->data.height);
        printf("\n=======================\n");
        currentstudent=currentstudent->next;

    }
}

// ----------------- REMOVE STUDENT INFO ------------------------


int REMOVE_by_ID()
{
    //scan id
    uint32 id;
    student * currentstudent=HEAD;
    student * prevstudent=NULL;
    printf("enter student ID: ");
    scanf("%d",&id);

    //loop to find id
    while(currentstudent != NULL)
    {
        if(currentstudent->data.ID == id)
        {
            //id of first student
            if(prevstudent == NULL)
            {
                 HEAD=currentstudent->next;
                 
            }
            else
            {
                prevstudent->next=currentstudent->next;
                
            }

            //removing and decrement counter
            free(currentstudent);
            counter--;
            return 1;

        }
        prevstudent = currentstudent;
        currentstudent = currentstudent->next;
    }

    printf("\ninvalid ID");
    return 0;

}

int REMOVE_by_index()
{
    //scan index
    uint32 index;
    printf("enter student index: ");
    scanf("%d",&index);
    student * currentstudent=HEAD;
    student * prevstudent=HEAD;
    uint32 i;
    // check index
    if (index <1)
    {
        printf("invalid index\n");
        return 0;
    }
    

    
    else
    {
       if(index==1)
      {
         HEAD=currentstudent->next;
      }
      else
      {
        for(i=1;i<index-1;i++)
        {
            // check if index more than list
            if(index>counter)
            {
                printf("invalid index");
                printf("\n=======================\n");
                 return 0;
            }
            prevstudent=prevstudent->next;
        }

        //store next of currentstudent to the next of the previous student
        currentstudent = prevstudent->next;
        prevstudent->next=currentstudent->next;

      }
       //removing and decrement counter
        free(currentstudent);
        counter--;
        return 1;
    }

printf("invalid index");
return 0;
}

void REMOVE_all()
{
    student * currentstudent=HEAD;
    while (currentstudent!= NULL)
    {
        HEAD=currentstudent->next;
        free(currentstudent);
        currentstudent=HEAD;
    }
    counter=0;


}


//------------------------ADDITIONAL FEATURES------------------------
void PRINT_MIDDLE()
{
    
    //you can also find middle by middle =counter/2 
    
    student * fast=HEAD;
    student * slow=HEAD;
    // check if fast reach null
    while ((fast!=NULL) && (fast->next !=NULL))
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("\nstudent ID: %d",slow->data.ID);
    printf("\nstudent name:  %s",slow->data.name);
    printf("\nstudent height: %.2f",slow->data.height);
    printf("\n=======================\n");


}
void PRINT_REV_INDEX()
{
    //scan index
    uint32 index;
    printf("enter student index: ");
    scanf("%d",&index);

    student * fast=HEAD;
    student * slow=HEAD;
    uint32 i;
    if(index>counter)
    {
        printf("invalid index");

    }
    else
    {
        for(i=0;i<index;i++)
    {
        fast=fast->next;
    }
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    printf("\nstudent ID: %d",slow->data.ID);
    printf("\nstudent name:  %s",slow->data.name);
    printf("\nstudent height: %.2f",slow->data.height);
    printf("\n=======================\n");

    }
    
}

void REVERSE_LIST ()
{
    student * current=HEAD->next;
    student * prev=HEAD;
    student * next = HEAD->next->next;
    if(!prev || !current)
    {
        printf("\n ----------List is Reversed \n");
    }
    else
    {
         while(current != NULL)
    {
        next=current->next;
        current->next =prev;
        prev=current;
        current=next;
    }
    HEAD = prev;
     printf("\n ----------List is Reversed \n");

    }
   
}

void SORT_LIST ()
{
    student * current=HEAD;
    student * temp_student;
    database  temp_data;
    uint32 i;
    for(i=1;i<counter;i++)
    {
        for(temp_student=current; temp_student->next!=NULL ; temp_student = temp_student->next)
        {
            if(temp_student->data.height > temp_student->next->data.height)
            {
                temp_data = temp_student->data;
                temp_student->data = temp_student->next->data;
                temp_student->next->data=temp_data;
            }

        }
       
    }
    printf("\n ----------List is sorted -----------------\n");

}


void fill_data(student * record)
{
    printf("\n=======================\n");
    printf("enter student ID: ");
    scanf("%d",&record->data.ID);
    printf("\nenter student name: ");
    fflush(stdin);
    gets(record->data.name);
    printf("\nenter student height: ");
    scanf("%f",&record->data.height);
    printf("\n=======================\n");
    
}

