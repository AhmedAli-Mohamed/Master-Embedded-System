# Ex1 :
### program to print matrix c which is the sum of 2 matrix a,b

### Note :

#### every matrix is 2*2

# Solution :


```c
# include<stdio.h>
void main()
{
    int i,j;
    float a[2][2],b[2][2],c[2][2];
    printf("Enter 1st matrix: \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Entera%d%d\n",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter 2nd matrix: \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Enterb%d%d\n",i,j);
            scanf("%f",&b[i][j]);
        }
    }
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%.2f\t",c[i][j]);
        }
        printf("\n");
    }

   
} 


```