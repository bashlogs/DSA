#include <stdio.h>
#include <stdlib.h>

// Structure of a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted doubly linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* mergedList;
    if (list1->data < list2->data) {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }
    mergedList->next->prev = mergedList;
    return mergedList;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    // Creating the first sorted doubly linked list
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->prev = list1;
    list1->next->next = createNode(5);
    list1->next->next->prev = list1->next;

    // Creating the second sorted doubly linked list
    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->prev = list2;
    list2->next->next = createNode(6);
    list2->next->next->prev = list2->next;

    // Displaying the first list
    printf("List 1: ");
    displayList(list1);
    printf("\n");

    // Displaying the second list
    printf("List 2: ");
    displayList(list2);
    printf("\n");

    // Merging the two sorted doubly linked lists
    struct Node* mergedList = mergeLists(list1, list2);

    // Displaying the merged list
    printf("Merged list: ");
    displayList(mergedList);

    return 0;
}
