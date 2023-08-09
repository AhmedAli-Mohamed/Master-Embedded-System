#ifndef FIFO_
#define FIFO_

#include<stdio.h>
#include"types.h"

//user configuration

#define SIZE 5
#define datatype uint32


//Data types

typedef struct
{
    datatype * base;
    uint32  head;
    uint32  tail;
    uint32 length;
    uint32 count;

}FIFO_BUF;

typedef enum
{
    FIFO_full,
    FIFO_empty,
    FIFO_no_error,
    FIFO_null

}FIFO_status;


//API functions
FIFO_status FIFO_init(FIFO_BUF *fifo, datatype * buf,uint32 size);
FIFO_status FIFO_Enqueue(FIFO_BUF *fifo, datatype item);
FIFO_status FIFO_Dequeue(FIFO_BUF *fifo, datatype * item);
FIFO_status FIFO_print(FIFO_BUF *fifo);






#endif