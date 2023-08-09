#include<stdio.h>
#include"lifo.h"

LIFO_status LIFO_init(LIFO_BUF *lifo, datatype * buf,uint32 size)
{
    lifo->base = buf;
    lifo->head = buf;
    lifo->length= size;
    lifo->count = 0;

}

LIFO_status LIFO_push(LIFO_BUF *lifo, datatype item)
{
    // check is stack null
    if(!lifo->head || !lifo->base || !&lifo)
    return LIFO_null;

    //check is stack full
    if (lifo->count >=lifo->length)
    return LIFO_full;

    //push item
    *(lifo->head) = item;
    lifo->head++;
    lifo->count++;
    return LIFO_no_error;
}

LIFO_status LIFO_pop(LIFO_BUF *lifo, datatype * item)
{
    // check is stack null
    if(!lifo->head || !lifo->base || !&lifo)
    return LIFO_null;

    //check is stack empty
    if (lifo->head ==lifo->base)
    return LIFO_empty;

    //pop item
    lifo->head--;
    *(item) = *(lifo->head);
    lifo->count--;
    return LIFO_no_error;
}

LIFO_status LIFO_print(LIFO_BUF *lifo)
{
    //check is stack empty
    if (lifo->head ==lifo->base)
    return LIFO_empty;

    //printing stack
    uint32 i;
    for(i=0;i<=lifo->count;i++)
    {
      printf("%d\n",lifo->base[i++]); 
    }
    return LIFO_no_error;

    
}