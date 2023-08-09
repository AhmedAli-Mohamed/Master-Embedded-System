#include<stdio.h>
#include"fifo.h"

void main() 
    {
        uint32 x;
        //Adding queue
        datatype item;
        FIFO_BUF uart;
        datatype uart_buf[SIZE];
        FIFO_init(&uart,uart_buf,SIZE);
        while(1)
        {
            printf("1-Enqueue item\n2-Dequeue item\n3-print queue\n\n");
            printf("Enter your choice :  ");
            scanf("%d",&x);

            switch(x)
            {
                case 1:
                scanf("%d",&item);
                 if(FIFO_Enqueue(&uart,item)==FIFO_no_error)
                 printf("%d has Enqueued\n\n\n",item);
                 else if(FIFO_Enqueue(&uart,item)==FIFO_null)
                 printf("queue is null\n\n\n");
                 else if(FIFO_Enqueue(&uart,item)==FIFO_full)
                 printf("queue is full\n\n\n");
                 break;

                 case 2:
                 if(FIFO_Dequeue(&uart,&item)==FIFO_no_error)
                 printf("%d has Dequeued\n\n\n",item);
                 else if (FIFO_Dequeue(&uart,&item)==FIFO_null)
                 printf("queue is null\n\n\n");
                 else if(FIFO_Dequeue(&uart,&item)==FIFO_empty)
                 printf("queue is empty\n\n\n");
                 break;

                 case 3 :
                 if(FIFO_print(&uart)==FIFO_no_error)
                 printf("====== All items printed =====\n\n\n\n");
                 else{
                    printf("queue is empty\n\n\n");
        
                 }
                 break;

            }
        }
      
    }