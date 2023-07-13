# Ex2 :
### program ask user to enter number of inputs and get the average of the inputs

# solution :
```c
#include <stdio.h>
void main ()
    {
        int  i,size;
        float sum=0,arr[100]={0};
        printf("Enter the number of data : \n");
        scanf("%d",&size);
        for(i=0;i<size;i++)
        {
            printf("Enter number : \n");
            scanf("%f",&arr[i]);
            sum=sum+arr[i];
        } 

        printf("Average=%.2f\n",sum/size);
        

    }


```