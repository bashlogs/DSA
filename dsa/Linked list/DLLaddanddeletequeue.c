#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// Queue structure
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add an element to the queue
void add(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        newNode->prev = q->rear;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to delete an element from the queue
int delete(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    } else {
        int data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        if (q->front != NULL) {
            q->front->prev = NULL;
        } else {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
}

// Function to display the queue
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
    } else {
        Node* temp = q->front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    add(&q, 10);
    add(&q, 20);
    add(&q, 30);
    add(&q, 40);

    display(&q); // Output: Queue elements: 10 20 30 40

    delete(&q); // Output: 10
    delete(&q); // Output: 20

    display(&q); // Output: Queue elements: 30 40

    return 0;
}
