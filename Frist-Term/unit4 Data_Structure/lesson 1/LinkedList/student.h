#ifndef STUDENT_
#define STUDENT_

#include<stdio.h>
#include"types.h"

//Datatypes

typedef struct data
{
    uint32 ID;
    uint8 name[20];
    float32 height;

}database;

typedef struct student
{
    database data;
    struct student * next ; 
}student;


//API functions
//Adding a new student
void AddStudent();


//print student info
int SEARCH_by_ID();
int SEARCH_by_index();
int print_list();

//Remove a student info
int  REMOVE_by_ID();
int  REMOVE_by_index();
void REMOVE_all();


// additional features
void PRINT_MIDDLE();
void PRINT_REV_INDEX();
void REVERSE_LIST ();
void SORT_LIST ();


void fill_data(student * record);








#endif