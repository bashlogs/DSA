#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


char stack[100];
int top = -1;

void push(char x){
  stack[++top] = x;
}

char pop(){
  if(top == -1)
    return -1;
  else
    return stack[top--];
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int priority(char x){
  if(x == '+' || x == '-')
    return 1;
  if(x == '*' || x == '/')
    return 2;
  else
    return 0;
}

void infixtoprefix(char *e)
{
    char prefix[20], *s, x;
    printf("Infix Expression: %s",e);
    char *infix = e;
    int i = -1;
    size_t size = sizeof(infix) / sizeof(infix[0]);
    strrev(infix);
    s = infix;

    while (*s != '\0')
    {
        if (isalnum(*s))
            prefix[++i] = *s;
        else if (*s == ')')
            push(*s);
        else if (*s == '(')
            while ((x = pop()) != ')')
                prefix[++i] = x;
        else
        {
            while (priority(stack[top]) >= priority(*s))
                prefix[++i] = pop();

            push(*s);
        }
        s++;
    }
    while (top != -1)
        prefix[++i] = pop();

    strrev(prefix);
    prefix[++i] = '\0';

    printf("\nPrefix Expression: %s", prefix);
}

int main(){
  char exp[] = "((A+B)*(C-D))/(E+F)";
  infixtoprefix(exp);
  return 0;
}
