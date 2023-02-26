#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a singly linked list
struct Node {
    int coeff;
    int power;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void append(struct Node** head_ref, int new_coeff, int new_power) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->coeff = new_coeff;
    new_node->power = new_power;
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

// Function to multiply two polynomials and return the result
struct Node* multiply(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    // Traverse through all the terms of poly1
    while (poly1 != NULL) {
        // Multiply the current term of poly1 with all terms of poly2
        struct Node* temp = poly2;
        while (temp != NULL) {
            // Multiply the coefficients and add the powers
            int coeff = poly1->coeff * temp->coeff;
            int power = poly1->power + temp->power;

            // Add the product to the result
            append(&result, coeff, power);

            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%dx^%d ", node->coeff, node->power);
        node = node->next;
        if (node != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Driver code
int main() {
    // Create first polynomial
    struct Node* poly1 = NULL;
    append(&poly1, 3, 2);
    append(&poly1, 5, 1);
    append(&poly1, 7, 0);
    printf("Polynomial 1: ");
    printList(poly1);

    // Create second polynomial
    struct Node* poly2 = NULL;
    append(&poly2, 4, 1);
    append(&poly2, 2, 0);
    printf("Polynomial 2: ");
    printList(poly2);

    // Multiply the two polynomials
    struct Node* result = multiply(poly1, poly2);
    printf("Result: ");
    printList(result);

    return 0;
}
