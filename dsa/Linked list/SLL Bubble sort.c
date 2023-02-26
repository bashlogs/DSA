#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to perform bubble sort on a linked list
void bubbleSort(Node** headRef) {
    int swapped;
    Node* current;
    Node* last = NULL;

    // Check for empty list or single node list
    if (*headRef == NULL || (*headRef)->next == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = *headRef;

        while (current->next != last) {
            if (current->data > current->next->data) {
                // Swap nodes
                Node* temp = current->next;
                current->next = temp->next;
                temp->prev = current->prev;
                if (current->prev != NULL) {
                    current->prev->next = temp;
                } else {
                    *headRef = temp;
                }
                temp->next = current;
                current->prev = temp;

                swapped = 1;
            }
            current = current->next;
        }

        last = current;
    } while (swapped);
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
    head->next->prev = head;
    head->next->next = createNode(8);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(1);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(7);
    head->next->next->next->next->prev = head->next->next->next;

    printf("Before Sorting:\n");
    display(head); // Output: List elements: 5 3 8 1 7

    bubbleSort(&head);

    printf("After Sorting:\n");
    display(head); // Output: List elements: 1 3 5 7 8

    return 0;
}

