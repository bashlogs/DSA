//Practical 8
#include<stdio.h>
#include<stdlib.h>
#define max 5
int top=-1,stack[max],i;
void push();
void pop();
void display();
int main(){
	int ch;
		while(1){
			printf("\n STACK MENU");
			printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
			printf("\n Enter the function to be performed: ");
			scanf("%d",&ch);
			switch(ch){
				case 1:push();
				break;
				case 2:pop();
				break;
				case 3:display();
				break;
				case 4: exit(0);
				default :printf("\n Enter appropriate choice");
			} //switch closing
	}//while closing
	return 0;
}
void push(){
	int val;
	if (top==max-1){
		printf("\n Stack is full");
	}
	else{
	printf("\n Enter the element to push: ");
	scanf("%d",&val);
	top=top+1;
	stack[top]=val;
	printf("\n Successfully added");
	}
}
void pop(){
	if(top==-1){
		printf("\n Stack empty");
	}
	else{
		printf("\n %d element is popped",stack[top]);
		top=top-1;
	}
}
void display(){   
	if(stack[top]!=-1){
		printf("\n The stack contains");
		for(i=0;i>=0;i++){
			printf("\t %d",stack[i]);
		}
	}
	else
		printf("\n Stack is empty");
}