#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to split the linked list into two sublists - one for the front half and one for the back half
void frontBackSplit(struct Node* source, struct Node** front_ref, struct Node** back_ref) {
    struct Node* slow_ptr = source;
    struct Node* fast_ptr = source;

    if (source == NULL || source->next == NULL) {
        *front_ref = source;
        *back_ref = NULL;
        return;
    }

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    *front_ref = source;
    *back_ref = slow_ptr->next;
    slow_ptr->next = NULL;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node* head = NULL;
    struct Node* front = NULL;
    struct Node* back = NULL;

    // Create the linked list
    append(&head, 2);
    append(&head, 3);
    append(&head, 5);
    append(&head, 7);
    append(&head, 11);

    // Split the linked list into two sublists - one for the front half and one for the back half
    frontBackSplit(head, &front, &back);

    // Print the two sublists
    printf("Front Half: ");
    printList(front);
    printf("Back Half: ");
    printList(back);

    return 0;
} 

