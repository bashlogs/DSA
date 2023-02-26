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

// Function to insert a node in the sorted list
void sortedInsert(Node** headRef, Node* newNode) {
    Node* current;
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to perform insertion sort on a linked list
void insertionSort(Node** headRef) {
    Node* sortedList = NULL;
    Node* current = *headRef;
    Node* next;

    while (current != NULL) {
        next = current->next;
        sortedInsert(&sortedList, current);
        current = next;
    }

    *headRef = sortedList;
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
    head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(8);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(7);

    printf("Before Sorting:\n");
    display(head); // Output: List elements: 5 3 8 1 7

    insertionSort(&head);

    printf("After Sorting:\n");
    display(head); // Output: List elements: 1 3 5 7 8

    return 0;
}

