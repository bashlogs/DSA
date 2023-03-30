#include <stdio.h>
#include <string.h>
#define MAX 100
int top=-1;
char stack[MAX];
int max = 100;
void push(char item)
{
    if(top == MAX-1)
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    stack[++top]=item;
}

char pop()
{
    if(top == -1)
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }
    return stack[top--];
}

void push1(char item)
{
    if(top == -1)
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    max--;
    stack[max]=item;
}

char pop1()
{
    if(top == max-1)
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }
    return stack[max++];
}

void concat(char data[], char data2[]){
  char new[MAX];
  for(int i=0; i<strlen(data);i++){
    push(data[i]);
  }
  for(int i=0; i<strlen(data2); i++){
    push(data2[i]);
  }
  int length = strlen(data) + strlen(data2);
  for(int i=length-1; i>=0; i--){
    new[i] = pop();
  }
  printf("Concat String: %s",new);
}

void compare(char data[], char data2[]){
  int check=1;
  for(int i=0; i<strlen(data);i++){
    push(data[i]);
  }
  for(int i=0; i<strlen(data2); i++){
    push1(data2[i]);
  }
  for(int i=0,y=strlen(data)+strlen(data2); i<strlen(data); i++, y--){
    if(pop() != pop1()){
      check=0;
    }
  }
  if(check==1){
    printf("\nBoth string are same");
  }
  else{
    printf("\nBoth strings are not same");
  }
}

int main(){
  char str[MAX];
  char str1[MAX];
  printf("Enter first string: ");
  scanf("%s",str);
  printf("Enter second string: ");
  scanf("%s",str1);
  //concat(str,str1);
  compare(str,str1);
}
