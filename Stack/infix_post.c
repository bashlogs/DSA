#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[20];
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

int priority(char x){
  if(x == '(')
    return 0;
  if(x == '+' || x == '-')
    return 1;
  if(x == '*' || x == '/')
    return 2;
}

void infix2post(char* exp){
  char *e, x;
  e = exp;
  while(*e != '\0'){
    if(isalpha(*e)){
      printf("%c",*e);
    }
    else if(*e == '('){
      push(*e);
    }
    else if(*e == ')'){
      while((x = pop()) != '('){
        printf("%c", x);
      }
    }
    else{
      while(priority(stack[top]) >= priority(*e))
        printf("%c", pop());
      push(*e);
    }
    e++;
  }
  while(top != -1){
    printf("%c",pop());
  }
}

int main(){
  char exp[20] = "((A+B)*(C-D))/(E+F)";
  printf("Infix: %s",exp);
  printf("\nPostfix: ");
  infix2post(exp);
  return 0;
}
