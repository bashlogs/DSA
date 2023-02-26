#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the contents of a doubly linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to append list1 to the start of list2
struct Node* appendToListStart(struct Node* list1, struct Node* list2) {
    // If either list is empty, return the other list
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    
    // Find the last node of list1
    struct Node* lastNode = list1;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    
    // Append list2 to the start of list1
    list2->prev = lastNode;
    lastNode->next = list2;
    
    return list1;
}

// Function to append list1 to the end of list2
struct Node* appendToListEnd(struct Node* list1, struct Node* list2) {
    // If either list is empty, return the other list
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    
    // Find the last node of list2
    struct Node* lastNode = list2;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    
    // Append list1 to the end of list2
    lastNode->next = list1;
    list1->prev = lastNode;
    
    return list2;
}

// Main function
int main() {
    // Creating the first list
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->prev = list1;
    list1->next->next = createNode(3);
    list1->next->next->prev = list1->next;
    list1->next->next->next = createNode(4);
    list1->next->next->next->prev = list1->next->next;
    printf("List 1: ");
    displayList(list1);
    printf("\n");

    // Creating the second list
    struct Node* list2 = createNode(5);
    list2->next = createNode(6);
    list2->next->prev = list2;
    list2->next->next = createNode(7);
    list2->next->next->prev = list2->next;
    printf("List 2: ");
    displayList(list2);
    printf("\n");
    
    // Appending list 1 to the start of list 2
    struct Node* startAppended = appendToListStart(list1, list2);
    printf("List after appending list 1 to the start of list 2: ");
displayList(startAppended);
printf("\n");
// Appending list 1 to the end of list 2
struct Node* endAppended = appendToListEnd(list1, list2);
printf("List after appending list 1 to the end of list 2: ");
displayList(endAppended);
printf("\n");

return 0;
}
