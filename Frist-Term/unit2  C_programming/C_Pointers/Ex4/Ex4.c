#include <stdio.h>
void main()
{
    int arr[15], size, i, *ptr;
    ptr = &arr;
    printf("Input the number of elements to store in the array (max 15) :");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("element -%d : ", i + 1);
        scanf("%d", arr + i);
    }
    printf("\n\nThe elements of array in reverse order are :\n");
    for (i = size - 1; i >= 0; i--)
    {

        printf("\nelement -%d : ", i + 1);
        printf("%d ", ptr[i]);
    }
}