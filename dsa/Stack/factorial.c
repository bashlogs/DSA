// program to implement following by using stack. A. Factorial of a given number B. Generation of Fibonacci series

#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(int c)
{
   stack[++top]=c;
}
int pop()
{
   return stack[top--];
}
int fact()
{
    int f=1;
    while(top!=-1){
        f=f*pop();
    }
    return f;
}
int main(){
    int n;
    printf("Factorial of a given number: ");
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        push(i);
    }
    printf("Factorial of %d is %d",n,fact());
    return 0;
}