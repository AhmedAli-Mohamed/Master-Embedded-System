#ifndef LIFO_
#define LIFO_

#include<stdio.h>
#include"types.h"

//user configuration

#define SIZE 5
#define datatype uint32


//Data types

typedef struct
{
    datatype * head;
    datatype * base;
    uint32 length;
    uint32 count;

}LIFO_BUF;

typedef enum
{
    LIFO_full,
    LIFO_empty,
    LIFO_no_error,
    LIFO_null

}LIFO_status;


//API functions
LIFO_status LIFO_init(LIFO_BUF *lifo, datatype * buf,uint32 size);
LIFO_status LIFO_push(LIFO_BUF *lifo, datatype item);
LIFO_status LIFO_pop(LIFO_BUF *lifo, datatype * item);
LIFO_status LIFO_print(LIFO_BUF *lifo);






#endif