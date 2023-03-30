#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* stack;
char* stack2;
int top = -1;
void push(char ele)
{
    stack[++top] = ele;
}
 
char pop()
{
    return stack[top--];
}

void Palindrome(char data[]){
  int i,mid;
  int length = strlen(data);
  stack = (char*)malloc(length*sizeof(char*));
  mid = length/2;
  for(i=0; i<mid; i++){
    push(data[i]);
  }
  if(length % 2 != 0){
    i++;
  }
  while(data[i] != '\0'){
    char string = pop();

    if(string != data[i])
      printf("\n%s is not a Palindrome",data);
    i++;
  }

  printf("%s is a Palindrome",data);
  free(stack);
}

int main(){
  Palindrome("MayuruyaM");
}
