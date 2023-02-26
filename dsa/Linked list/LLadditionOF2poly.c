#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a singly linked list
struct Node {
    int coeff;
    int power;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void append(struct Node** head_ref, int coeff, int power) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->coeff = coeff;
    new_node->power = power;
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

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            append(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            append(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            append(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        append(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        append(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print the polynomial in standard form
void printPolynomial(struct Node* node) {
    while (node != NULL) {
        printf("%dx^%d", node->coeff, node->power);

        if (node->next != NULL) {
            printf(" + ");
        }

        node = node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Create the first polynomial
    append(&poly1, 3, 2);
    append(&poly1, 4, 1);
    append(&poly1, 2, 0);
    printf("Polynomial 1: ");
    printPolynomial(poly1);

    // Create the second polynomial
    append(&poly2, 5, 1);
    append(&poly2, 2, 0);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);
    printf("Result: ");
    printPolynomial(result);

    return 0;
}
