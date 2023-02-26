#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// Stack structure
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack* s, int data) {
    Node* newNode = createNode(data);
    if (s->top == NULL) {
        s->top = newNode;
    } else {
        s->top->next = newNode;
        newNode->prev = s->top;
        s->top = newNode;
    }
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int data = s->top->data;
        Node* temp = s->top;
        s->top = s->top->prev;
        if (s->top != NULL) {
            s->top->next = NULL;
        }
        free(temp);
        return data;
    }
}

// Function to display the stack
void display(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
    } else {
        Node* temp = s->top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

int main() {
    Stack s;
    s.top = NULL;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    display(&s); // Output: Stack elements: 40 30 20 10

    pop(&s); // Output: 40
    pop(&s); // Output: 30

    display(&s); // Output: Stack elements: 20 10

    return 0;
}

