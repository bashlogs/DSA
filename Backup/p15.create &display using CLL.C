#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next,*previous;
}*start=NULL;
void create();
void display();
int main(){
    int ch;
    while (1){
        printf("\n Circular linked list menu->");
        printf("\n 1.Create a node \n 2.Display the node \n 3.Exit");
        printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();break;
            case 2:display();break;
            case 3:exit(0);
            default:printf("\n Wrong choice.");
        }
    }
    return 0;
}
void create(){
    int i,n;
    struct node*temp;
    printf("\n Enter the no of nodes to be created: ");
    scanf("%d",&n);
    if(n>=1){
        start=(struct node*)malloc(sizeof(struct node));
        printf("\n Enter data: ");
        scanf("%d",&start->info);
        temp=start;
        for(i=2;i<=n;i++){
            temp->next=(struct node*)malloc(sizeof(struct node));
            temp=temp->next;
            printf("\n Enter next data:");
            scanf("%d",&temp->info);
        }
        temp->next=NULL;
    }
    else{
        printf("\n not created");
    }
}
void display(){
    struct node*ptr;
    ptr=start;
    if(start==NULL)
        printf("\n List empty.");
    else{
        printf("\n %d",ptr->info);
        ptr=ptr->next;
        while(ptr!=start){
            printf("\t%d",ptr->info);
            ptr=ptr->next;
        }
    }
}