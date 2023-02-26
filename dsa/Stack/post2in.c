#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[50];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
void convert(char exp[])
{
    printf("Postfix expression is: %s",exp);
    int l, i, j = 0;
    char a, b, op[20];
    strrev(exp);
    l = strlen(exp);
    for (i = 0; i < 50; i++)
        stack[i] = '\0';
    printf("\nInfix expression is : ");
    for (i = 0; i < l; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            push(exp[i]);
        }
        else
        {
            op[j++] = exp[i];
            op[j++] = pop();
        }
    }
    op[j] = exp[top--];
    strrev(op);
    printf("%s",op);
}

int main()
{
    char exp[50] = "AB+CD-*EF+/";
    convert(exp);
    return 0;
}