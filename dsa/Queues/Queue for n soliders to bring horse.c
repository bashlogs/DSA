#include <stdio.h>
#include <stdlib.h>

// structure for a soldier
struct soldier {
    int id;
    struct soldier* next;
};

// function to create a circular linked list of soldiers
struct soldier* create_soldiers(int n) {
    // create first soldier
    struct soldier* head = (struct soldier*)malloc(sizeof(struct soldier));
    head->id = 1;
    head->next = head;
    
    // create remaining soldiers and add them to the circle
    struct soldier* current = head;
    for (int i = 2; i <= n; i++) {
        struct soldier* new_soldier = (struct soldier*)malloc(sizeof(struct soldier));
        new_soldier->id = i;
        new_soldier->next = head;
        current->next = new_soldier;
        current = new_soldier;
    }
    
    return head;
}

// function to simulate the game and find the soldier who will go out
int find_soldier_to_go_out(struct soldier* head, int m) {
    // find the last soldier standing
    struct soldier* current = head;
    while (current->next != current) {
        // find the m-th soldier and remove him from the circle
        for (int i = 1; i < m - 1; i++) {
            current = current->next;
        }
        struct soldier* temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
    
    return current->id;
}

int main() {
    int n, m;
    printf("Enter the number of soldiers and the value of m: ");
    scanf("%d %d", &n, &m);
    
    // create the circle of soldiers
    struct soldier* head = create_soldiers(n);
    
    // find the soldier who will go out
    int soldier_to_go_out = find_soldier_to_go_out(head, m);
    
    printf("Soldier %d will go out to seek help.\n", soldier_to_go_out);
    
    return 0;
}
