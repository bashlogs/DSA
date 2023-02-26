#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void deleteAtPosition(struct Node** head, int position) {
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;
    for (int i = 1; i < position && current != NULL; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    printf("Linked list after inserting nodes at the beginning: ");
    printList(head);

    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);

    printf("Linked list after inserting nodes at the end: ");
    printList(head);

    insertAtPosition(&head, 30, 2);

    printf("Linked list after inserting a node at position 2: ");
    printList(head);

    deleteAtBeginning(&head);
    printf("Linked list after deleting the first node: ");
    printList(head);

    deleteAtEnd(&head);

    printf("Linked list after deleting the last node: ");
    printList(head);

    deleteAtPosition(&head, 2);

    printf("Linked list after deleting the node at position 2: ");
    printList(head);

    return 0;
}

