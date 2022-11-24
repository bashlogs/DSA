#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node*next,*prev;
}*start=NULL;
void create();
void insert();
void display();
void search();
void del();
int main(){
	int ch;
	while(1){
		printf("\n DOUBLY LINKED LIST MENU");
		printf("\n 1.Create a node");
		printf("\n 2.Insert a node");
		printf("\n 3.Delete a node");
		printf("\n 4.Search a particular node");
		printf("\n 5.Display all nodes");
		printf("\n 6.EXIT");
		printf("\n Enter your choice");
		scanf("%d",&ch);
		switch(ch){
			case 1: create();
				break;
			case 2:insert();
				break;
			case 3:del();
				break;
			case 4:search();
				break;
			case 5:display();
				break;
			case 6: exit(0);
			default:printf("\n Enter proper choice");
		}
	}
}
void create(){
	int i, n;
	struct node *temp;
	printf("\n How many nodes you want to create?");
	scanf("%d",&n);
		if(n>=1){
			start=(struct node*)malloc(sizeof(struct node));
			printf("\n Enter data");
			scanf("%d",&start->info);
			start->prev=NULL;
			for(i=2,temp=start;i<=n;i++){
				temp->next=(struct node*)malloc(sizeof(struct node));
				temp->next->prev=temp;
				temp=temp->next;
				printf("\n Enter next data");
				scanf("%d",&temp->info);
			}
			temp->next=NULL;
		}
		else{
		printf("\n List is not created");
		}
}
void insert(){
	int loc,i;
	struct node*temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter location");
	scanf("%d",&loc);
	printf("\n Enter data");
	scanf("%d",&temp->info);
		if(loc==1){
			temp->next=start;
			start=temp;
			start->prev=NULL;
		}
		else{
			for(i=0,ptr=start;i<loc&&ptr->next!=NULL;i++){
				ptr=ptr->next;
			}
			if(temp==NULL||(loc<1)){
				printf("\n Invalid");
			}
			else{
				temp->prev=ptr;
				temp->next=ptr->next;
				ptr->next=temp;
			}
		}
}
void del(){
	if(start==NULL){
		printf("\n List is empty");
	}
	else{
		int loc,i;
		struct node*temp,*ptr;
		printf("\n Enter location");
		scanf("%d",&loc);
		if(loc==1){
			temp=start;
			start=start->next;
			start->prev=NULL;
			printf("\n %d node is deleted");
			free(temp);
		}
		else{
			ptr=start;
			for(i=2;i<loc&&ptr!=NULL;i++){
				ptr=ptr->next;
			}
			if(ptr==NULL||i<1)
				printf("\n Invalid");
			else{
				temp=ptr->next;
				ptr->next=temp->next;
				ptr=temp->prev;
				printf("\n %d node is deleted",temp->info);
				free(temp);
			}
		}
	}
}
void display(){
	if(start==NULL){
		printf("\n List is empty");
	}
	else{
		struct node*temp;
		temp=start;
		while(temp!=NULL){
			printf("\t%d",temp->info);
			temp=temp->next;
		}
	}
}
void search(){
	int data,i=1;
	struct node*temp;
	printf("\n Enter data");
	scanf("%d",&data);
	temp=start;
	while(temp!=NULL){
		if(data==temp->info){
			printf("\n %d data is present at location %d",data,i);
			return;
		}
		else{
			temp=temp->next;
			i++;
		}
		if(temp==NULL){
			printf("\n %d is not present in list");
		}
	}
}
