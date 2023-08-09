#include<stdio.h>
#include"types.h"
#include"fifo.h"




    FIFO_status FIFO_init(FIFO_BUF *fifo, datatype * buf,uint32 size)
{
    fifo->base = buf;
    fifo->head = 0;
    fifo->tail =0;
    fifo->length= size;
    fifo->count = 0;

}

FIFO_status FIFO_Enqueue(FIFO_BUF *fifo, datatype item)
{
    //check is queue null
    if(!fifo->base ||!&fifo)
    return FIFO_null;

    //check is queue full
    if (fifo->count == fifo->length)
    return FIFO_full;

    //Enqueue item
    fifo->base[fifo->head]  = item;
    fifo->count++;
    fifo->head = (fifo->head + 1)%fifo->length;
    return FIFO_no_error;
}

FIFO_status FIFO_Dequeue(FIFO_BUF *fifo, datatype * item)
{
    //check is queue null
    if(!fifo->base || !&fifo)
    return FIFO_null;

    // check is queue empty
    if(fifo->count == 0)
    return FIFO_empty;

    //Dequeue item
    *item = fifo->base[fifo->tail];
    fifo->count--;
    fifo->tail = (fifo->tail + 1)%fifo->length;
    return FIFO_no_error;
}
FIFO_status FIFO_print(FIFO_BUF *fifo)
{
    // check is queue empty
    if(fifo->count == 0)
    return FIFO_empty;

    //printing queue
    uint32 i,tail1;
    tail1=fifo->tail;
    for(i=0;i<fifo->count;i++)
    {
        printf("%d\n",fifo->base[tail1]);
        tail1 = (tail1 +1)%fifo->length;
    }
    return FIFO_no_error;

}