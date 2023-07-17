#include<stdio.h>
void repeated(int arr[],int size);
void main()
{
    int i,size,arr[100];
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    printf("Enter the elements of the array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    repeated(arr,size);
}

void repeated(int arr[],int size)
{
    int i,j,res[100],k=0,flag=-1;
    for (i=0,j=0;j<size;i++)
    {
        if (i==size)
        {
            
            if (flag==0)
            {
                res[k]=arr[j];
                k++;
            }
            i=0;
            j++;
            flag = -1;
        }
        if (arr[i] == arr[j])
        {
            flag++;
        }
    }
    for (i=0;i<k;i++)
    {
        printf("%d\n",res[i]);
    }
}