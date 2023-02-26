#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
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

// Function to append list b to the end of list a
void Append(struct Node** a_ref, struct Node** b_ref) {
    if (*a_ref == NULL) {
        *a_ref = *b_ref;
        *b_ref = NULL;
        return;
    }

    struct Node* last_a = *a_ref;
    while (last_a->next != NULL) {
        last_a = last_a->next;
    }

    last_a->next = *b_ref;
    *b_ref = NULL;
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
    struct Node* a = NULL;
    struct Node* b = NULL;

    // Create list a
    append(&a, 1);
    append(&a, 2);
    append(&a, 3);
    printf("List a: ");
    printList(a);

    // Create list b
    append(&b, 4);
    append(&b, 5);
    append(&b, 6);
    printf("List b: ");
    printList(b);

    // Append list b to list a
    Append(&a, &b);
    printf("List a after appending list b: ");
    printList(a);
    printf("List b after appending list b: ");
    printList(b);

    return 0;
}


