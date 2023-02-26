#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** headRef, Node* newNode) {
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove duplicate nodes from a sorted list
void removeDuplicates(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Function to display a linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        Node* temp = head;
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, createNode(1));
    insertAtEnd(&head, createNode(2));
    insertAtEnd(&head, createNode(2));
    insertAtEnd(&head, createNode(3));
    insertAtEnd(&head, createNode(3));
    insertAtEnd(&head, createNode(3));
    insertAtEnd(&head, createNode(4));
    insertAtEnd(&head, createNode(5));
    insertAtEnd(&head, createNode(5));

    printf("Before removing duplicates:\n");
    display(head); // Output: List elements: 1 2 2 3 3 3 4 5 5

    removeDuplicates(head);

    printf("After removing duplicates:\n");
    display(head); // Output: List elements: 1 2 3 4 5

    return 0;
}


