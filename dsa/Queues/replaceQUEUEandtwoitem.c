#include <stdio.h>
#define MAXSIZE 100

int queue[MAXSIZE];
int front1 = -1, rear1 = -1, front2 = MAXSIZE, rear2 = MAXSIZE;

void addq(int value, int queueNum) {
    if (queueNum == 1) {
        if (rear1 == MAXSIZE-1) {
            printf("Queue 1 is full.\n");
        } else {
            if (front1 == -1) front1 = 0;
            rear1++;
            queue[rear1] = value;
            printf("Element added to Queue 1.\n");
        }
    } else if (queueNum == 2) {
        if (rear2 == front1+1) {
            printf("Queue 2 is full.\n");
        } else {
            if (front2 == MAXSIZE) front2 = MAXSIZE-1;
            rear2--;
            queue[rear2] = value;
            printf("Element added to Queue 2.\n");
        }
    } else {
        printf("Invalid queue number.\n");
    }
}

void delq(int queueNum) {
    if (queueNum == 1) {
        if (front1 == -1 || front1 > rear1) {
            printf("Queue 1 is empty.\n");
        } else {
            printf("Element deleted from Queue 1: %d\n", queue[front1]);
            front1++;
        }
    } else if (queueNum == 2) {
        if (front2 == MAXSIZE || front2 < rear2) {
            printf("Queue 2 is empty.\n");
        } else {
            printf("Element deleted from Queue 2: %d\n", queue[front2]);
            front2--;
        }
    } else {
        printf("Invalid queue number.\n");
    }
}

void display(int queueNum) {
    if (queueNum == 1) {
        if (front1 == -1 || front1 > rear1) {
            printf("Queue 1 is empty.\n");
        } else {
            printf("Elements in Queue 1: ");
            for (int i = front1; i <= rear1; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    } else if (queueNum == 2) {
        if (front2 == MAXSIZE || front2 < rear2) {
            printf("Queue 2 is empty.\n");
        } else {
            printf("Elements in Queue 2: ");
            for (int i = front2; i >= rear2; i--) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid queue number.\n");
    }
}

int main() {
    int choice, value, queueNum;
    while (1) {
        printf("1. Add element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the queue number (1 or 2): ");
                scanf("%d", &queueNum);
                printf("Enter the value to be added: ");
                scanf("%d", &value);
                addq(value, queueNum);
                break;
            case 2:
                printf("Enter the queue number (1 or 2): ");
                scanf("%d",            &queueNum);
            delq(queueNum);
            break;
        case 3:
            printf("Enter the queue number (1 or 2): ");
            scanf("%d", &queueNum);
            display(queueNum);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
    }
}
}
