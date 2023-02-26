#include <stdio.h>
#define SIZE 10
#define NO 5

int Stack[NO][SIZE];
int top[NO] = {-1,-1,-1,-1,-1};

void push(int data, int no){
  if(top[no] == SIZE-1){
    printf("\nStack %d Overflow",no);
  }
  else{
    Stack[no][++top[no]] = data;
  }
}

int pop(int no){
  if(top[no] == -1){
    printf("\nStack %d UnderFlow",no);
  }
  else{
    return Stack[no][top[no]--];
  }
}

void display(int no){
  if(top[no] >= 0){
    printf("\nStack %d: ",no);
    for(int i=0; i<=top[no]; i++){
      printf("\t%d",Stack[no][i]);
    }
  }
  else{
    printf("\nStack is Empty");
  }
}

void stackfull(){
  for(int i=0; i<NO; i++){
    if(top[i] == SIZE){
      printf("\nStack %d is Full",i);
    }
  }
}

void stackempty(){
  for(int i=0; i<NO; i++){
    if(top[i] == -1){
    printf("\nStack %d is Empty", i);
  }

  }
}
int main(){
  push(10,0);
  push(20,0);
  push(20,1);
  push(30,2);
  push(40,3);
  push(50,4);
  display(0); 
  display(1);
  display(2);
  display(3);
  display(4);
  printf("\nPop 0: %d",pop(0));
  printf("\nPop 1: %d",pop(1));
  printf("\nPop 2: %d",pop(2));
  printf("\nPop 3: %d",pop(3));
  printf("\nPop 4: %d",pop(4));
  printf("\nPop 0: %d",pop(0));
  pop(2);
  pop(0);
  stackfull();
  stackempty();
}
