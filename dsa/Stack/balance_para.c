// program to accept a string of parenthesis and check its validity by using stack.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
char stack[MAX];
int top=-1;
int top1=-1;
void push(char c)
{
    ++top1;
   stack[++top]=c;

}
char pop()
{
   return stack[top--];
}

int isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}   

int isParathesisBalanced(char *paranthesis){
    for(int i=0; i<strlen(paranthesis);i++){
        if(paranthesis[i]=='(' || paranthesis[i]=='{' || paranthesis[i]=='['){
            push(paranthesis[i]);
        }
        else if(paranthesis[i]==')' || paranthesis[i]=='}' || paranthesis[i]==']'){
            if(top==-1 || !isMatchingPair(stack[top],paranthesis[i])){
                return 0;
            }
            else{
                pop();
            }
        }
    }
    return top == -1;
}

int main(){
    char paranthesis[MAX];
    printf("Enter the paranthesis: ");
    gets(paranthesis);
    if(isParathesisBalanced(paranthesis)){
        printf("Balanced");
    }
    else{
        printf("Not Balanced");
    }
    return 0;
}