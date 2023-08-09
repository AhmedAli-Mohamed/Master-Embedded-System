#include<stdio.h>
#include"lifo.h"

void main() 
    {
        uint32 x;
        //Adding stack
        datatype item;
        LIFO_BUF uart;
        datatype uart_buf[SIZE];
        LIFO_init(&uart,uart_buf,SIZE);
        while(1)
        {
            printf("1-push item\n2-pop item\n3-print stack\n\n");
            printf("Enter your choice :  ");
            scanf("%d",&x);

            switch(x)
            {
                case 1:
                scanf("%d",&item);
                 if(LIFO_push(&uart,item)==LIFO_no_error)
                 printf("%d has pushed\n\n\n",item);
                 else if(LIFO_push(&uart,item)==LIFO_null)
                 printf("Stack is null\n\n\n");
                 else if(LIFO_push(&uart,item)==LIFO_full)
                 printf("Stack is full\n\n\n");
                 break;

                 case 2:
                 if(LIFO_pop(&uart,&item)==LIFO_no_error)
                 printf("%d has poped\n\n\n",item);
                 else if (LIFO_pop(&uart,&item)==LIFO_null)
                 printf("Stack is null\n\n\n");
                 else if(LIFO_pop(&uart,&item)==LIFO_empty)
                 printf("Stack is empty\n\n\n");
                 break;

                 case 3 :
                 if(LIFO_print(&uart)==LIFO_no_error)
                 printf("====== All items printed =====\n\n\n\n");
                 else{
                    printf("stack is empty\n\n\n");
        
                 }
                 break;

            }
        }
      
    }