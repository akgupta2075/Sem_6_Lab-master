/*
Question: Write a C program to parse the given string using Recursive Descent Parser.

Input: a+a*a
OUTPUT BY AMIT:E->TE'T->FT'F->aT'->^E'->+TE'T->FT'F->aT'->*FT'F->aT'->^E'->^string sucessfully parsed!

Output: string parsed successfully!
*/

#include <stdio.h>
#include <string.h>
int i = 0, f = 0;
char str[30];

int E();
int Eprime();
int T();
int Tprime();
int F();

int E()
{
    printf("E->TE'");
    T();
    Eprime();
    return 0;
}

int Eprime()
{
    if (str[i] == '+')
    {
        printf("E'->+TE'");
        i++;
        T();
        Eprime();
    }
    else if ((str[i] == ')') || (str[i] == '$'))
        printf("E'->^");
    return 0;
}

int T()
{
    printf("T->FT'");
    F();
    Tprime();
    return 0;
}

int Tprime()
{
    if (str[i] == '*')
    {
        printf("T'->*FT'");
        i++;
        F();
        Tprime();
    }

    else if ((str[i] == ')') || (str[i] == '+') || (str[i] == '$'))
    {
        printf("T'->^");
    }
    return 0;
}

int F()
{
    if (str[i] == 'a')
    {
        printf("F->a");
        i++;
    }

    else if (str[i] == '(')
    {
        printf("F->(E)");
        i++;
        E();
        if (str[i] == ')')
            i++;
    }
    else
        f = 1;
    return 0;
}

int main()
{
    int len;
    scanf("%s", str);
    len = strlen(str);
    str[len] = '$';
    E();
    if ((str[i] == '$') && (f == 0))
        printf("string sucessfully parsed!");
    else
        printf("syntax Error!");
    return 0;
}
