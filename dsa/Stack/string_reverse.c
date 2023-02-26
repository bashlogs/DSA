#include <stdio.h>
#include <string.h>
#define MAX 100
int top=-1;
int item;
char stack[MAX];

void pushChar(char item)
{
    if(top == MAX-1)
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    stack[++top]=item;
}

char popChar()
{
    if(top == -1)
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }
    return stack[top--];
}
int main()
{
    char str[MAX];
    
    int i;
    
    printf("Input a string: ");
    scanf("%[^\n]s",str);
    
    for(i=0;i<strlen(str);i++)
        pushChar(str[i]);
        
    for(i=0;i<strlen(str);i++)
        str[i]=popChar();

    printf("Reversed String is: %s\n",str);
    
    return 0;
}
