#include<stdio.h>
void insert(int);
int delete();
void display();
int queue[5],front=-1,rear=-1;
int item;
int main(){
    int ch,x,ditem;
    while(1){
        printf("\n QUEUE menu");
        printf("\n 1.Insert element into queue \n 2.Delete element from queue \n3.Display element");
        printf("\n 4.Exit");
        printf("\n Enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\n Enter element to insert");
            scanf("%d",&x);
            insert(x);
            break;
            case 2: ditem=delete();
            printf("\n %d is deleted");
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default:printf("\n wrong choice");
        }
    }
    return 0;
}
void insert(int item){
    if(rear==4)
        printf("\n Queue is full");
    else{
        if(front==-1)
        front++;
        rear++;
        queue[rear]=item;
        printf("\n %d is inserted",item);
    }
}

int delete(){  
    int ditem;
    if(front==-1&&rear==-1)
        printf("\n The queue is empty");
    else{
        ditem=queue[front];
        if(front==rear)
            front=rear-1;
        else{
            front++;
        }
    }
    return ditem;
}
void display(){
    int temp;
    printf("\n The queue elements are ");
    for(temp=front;temp<=rear;temp++){
        printf("\t%d",queue[temp]);
    }
}