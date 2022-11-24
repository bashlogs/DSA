#include<stdio.h>
#include <stdlib.h>
void enqueue(int x);
void dequeue();void display();
#define n 5
int queue[n];
int item,front=-1,rear=-1;
int main(){
	int ch, x,ditem;
	while(1){
		printf("\n CIRCULAR QUEUE ");
		printf("\n 1.Enqueue data \n 2.Dequeue data \n3.display the contents \n 4.exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("\n Enter element to insert: ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: dequeue();break;
			case 3: display();break;
			case 4: exit(0);
			default:printf("\n Enter proper choice.");
		}
	}
}
void enqueue(int x){
	if(front==-1&&rear==-1){
		front=rear=0;
		printf("\nThe list was empty.");
		queue[rear]=x;
	}
	else if(((rear+1)%n)==front){
		printf("\nList is full.");
	}
	else{
		rear=(rear+1)%n;
		queue[rear]=x;
	}
}
void dequeue(){
	if(front==-1&&rear==-1)
	printf("\n Queue is empty");
		else if(front==rear)
		{ printf("\n %d is delete.",queue[front]);
		front=rear=-1;
		}
		else
		{
		printf("\n %d is dequeued.",queue[front]);
		front=(front+1)%n;
		}
}
void display(){
	int temp=front;
	if(front==-2&&rear==-1){
	printf("\n The queue is empty.");
	}
	else{
		printf("\n The queue is: ");
		while(temp!=rear){
			printf("\t%d",queue[temp]);
			temp=(temp+1)%5;
		}
	}
}