#ifndef QUEUE_
#define QUEUE_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//data types
typedef struct
{
    char fname[20];
    char lname[20];
    int roll;
    float gpa;
    int cid[5];
}sinfo;

// user configuration (configure number of student to be scanned from a fike.txt)
#define file_size 4



//APIS
/*------------Adding student----------------*/
void ADD_manually();
void ADD_FROM_FILE();

/*------------searching on student----------------*/
int Find_byRoll();
int Find_byFname();
void Find_byCID();
void find_all();

/*------------Deleting a  student----------------*/
int Delete_byRoll();

/*------------Updating INFO---------------*/
 int update_info();
void print_all_();



#endif