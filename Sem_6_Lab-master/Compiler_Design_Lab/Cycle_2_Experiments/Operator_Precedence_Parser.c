/*
Question: Write a C program to parse the given string using Operator Precedence Parser.
Input: ->>><><><>>><<<-
Output: Shift aReduceShift +Shift aReduceShift *Shift aReduceReduceReduceString is accepted
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char stack[20], arr[10][10];
    int i, j, k, n = 4, top = 0, col, row;
    char temp[] = {'a', '+', '*', '$'};
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }
    stack[top] = '$';
    char ip[] = {'a', '+', 'a', '*', 'a', '$'};
    i = 0;
    while (i <= strlen(ip))
    {
        for (k = 0; k < n; k++)
        {
            if (stack[top] == temp[k])
                row = k;
            if (ip[i] == temp[k])
                col = k;
        }
        if ((stack[top] == '$') && (ip[i] == '$'))
        {
            printf("String is accepted");
            break;
        }
        else if ((arr[row][col] == '<') || (arr[row][col] == '='))
        {
            stack[++top] = arr[row][col];
            stack[++top] = ip[i];
            printf("Shift %c", ip[i]);
            i++;
        }
        else
        {
            if (arr[row][col] == '>')
            {
                while (stack[top] != '<')
                    --top;
                top = top - 1;
                printf("Reduce");
            }
            else
            {
                printf("String is not accepted");
                break;
            }
        }
    }
    return 0;
}
