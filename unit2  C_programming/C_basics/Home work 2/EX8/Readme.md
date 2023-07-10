# EX8 :
### program to make arithmetic operations on two numbers

# Solution

```c
#include <stdio.h>
void main()
{
    int oprend1, oprend2;
    char operator;

    printf("Enter operator either + or - or * or / :  ");
    scanf("%c", &operator);
    printf("Enter two numbers :  ");
    scanf("%d%d", &oprend1, &oprend2);

    switch (operator)
    {
    case '+':
        printf("%d + %d = %d", oprend1, oprend2, oprend1 + oprend2);
        break;

    case '-':
        printf("%d - %d = %d", oprend1, oprend2, oprend1 - oprend2);
        break;
    case '*':
        printf("%d * %d = %d", oprend1, oprend2, oprend1 * oprend2);
        break;
    case '/':
        printf("%d / %d = %d", oprend1, oprend2, oprend1 / oprend2);
        break;

    default:
        printf("Invalid operator");
        break;
    }
}
```