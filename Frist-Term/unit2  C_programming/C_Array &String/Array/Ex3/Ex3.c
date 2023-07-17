#include <stdio.h>
void main()
{
    int i, j, rows, column, arr[100][100], trans[100][100];
    printf("Enter rows and columns of the matrix :  ");
    scanf("%d%d",&rows,&column);
    printf("Enter the elements of the matrix :  \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("Enter element a%d%d : ", i, j);
            scanf("%d", &arr[i][j]);
            trans[j][i] = arr[i][j];
        }
    }
    printf("Entered matrix : \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of the matrix : \n");

    for (i = 0; i < column; i++)
    {

        for (j = 0; j < rows; j++)
        {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }
}
