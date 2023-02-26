#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
char stack[MAX][MAX];
int top=-1;
void push(char c[])
{
   strcpy(stack[++top],c);
}
char* pop()
{
   return stack[top--];
}
int main(){
    char name[MAX];
    printf("Enter your name: ");
    gets(name);
    char *token = strtok(name, " ");

    while(token!=NULL){
        push(token);
        token = strtok(NULL, " ");
    }
    while(top!=-1){
        printf("%s ",pop());
    }
    return 0;
}