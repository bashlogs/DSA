#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Error: Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue is empty\n");
        return;
    }
    printf("Passenger at the front of the queue: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Passengers in the queue:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, passenger;
    do {
        printf("\nQueue Menu\n");
        printf("1. Add a passenger to the queue\n");
        printf("2. Remove the passenger at the front of the queue\n");
        printf("3. Display the passengers in the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the passenger number: ");
                scanf("%d", &passenger);
                enqueue(passenger);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    printf("Number of passengers left in the queue: %d\n", rear - front + 1);
    return 0;
}

