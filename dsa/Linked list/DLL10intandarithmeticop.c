#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10

// Doubly linked list node
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertNode(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
        *headRef = newNode;
    }
}

// Function to print the list in reverse order
void printReverse(struct node* head) {
    struct node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    while (tail != NULL) {
        printf("%d", tail->data);
        tail = tail->prev;
    }
}

// Function to add two numbers represented as linked lists
struct node* add(struct node* num1, struct node* num2) {
    struct node* result = NULL;
    int carry = 0;
    while (num1 != NULL || num2 != NULL) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        insertNode(&result, sum);
    }
    if (carry > 0) {
        insertNode(&result, carry);
    }
    return result;
}

// Function to subtract two numbers represented as linked lists
struct node* subtract(struct node* num1, struct node* num2) {
    struct node* result = NULL;
    int borrow = 0;
    while (num1 != NULL || num2 != NULL) {
        int diff = borrow;
        if (num1 != NULL) {
            diff += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            diff -= num2->data;
            num2 = num2->next;
        }
        if (diff < 0) {
            borrow = -1;
            diff += 10;
        } else {
            borrow = 0;
        }
        insertNode(&result, diff);
    }
    while (result->data == 0 && result->next != NULL) {
        result = result->next;
    }
    return result;
}

int main() {
    char str1[MAX_DIGITS+1];
    char str2[MAX_DIGITS+1];
    printf("Enter first number (up to %d digits): ", MAX_DIGITS);
    scanf("%s", str1);
    printf("Enter second number (up to %d digits): ", MAX_DIGITS);
    scanf("%s", str2);

    // Create linked lists for the two numbers
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    struct node* num1 = NULL;
    struct node* num2 = NULL;
    for (int i = len1-1; i >= 0; i--) {
        int digit = str1[i] - '0';
        insertNode(&num1, digit);
    }
    for (int i = len2-1; i >= 0; i--) {
        int digit = str2[i] - '0';
        insertNode(&num2, digit);
    }

    // Perform arithmetic operations
    struct node* sum = add(num1, num2);
    struct node* diff = subtract(num1, num2);

    // Print results
    printf("Sum: ");
    printReverse(sum);
    printf("\n");
    printf("Difference: ");
    printReverse(diff);
    printf("\n");

    return 0;
}

