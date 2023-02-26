#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a new node to the end of a linked list
void append(Node** headRef, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    Node* last = *headRef;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// Function to create a complete copy of a linked list
Node* CopyList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* newHead = NULL;
    Node* tail = NULL;

    // Iterate over the original list
    Node* current = head;
    while (current != NULL) {
        // Create a new node and copy the data
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = current->data;
        newNode->next = NULL;

        // Update the head or tail of the new list if needed
        if (newHead == NULL) {
            newHead = newNode;
            tail = newHead;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }

        current = current->next;
    }

    return newHead;
}

// Function to print a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Test the CopyList() function
int main() {
    Node* list = NULL;
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);

    printf("Original list: ");
    printList(list);

    Node* copy = CopyList(list);
    printf("Copied list: ");
    printList(copy);

    return 0;
}
