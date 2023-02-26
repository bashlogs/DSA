#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void Reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

void Insert(Node** head_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void PrintList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);

    printf("Original list: ");
    PrintList(head);

    Reverse(&head);

    printf("Reversed list: ");
    PrintList(head);

    return 0;
}
