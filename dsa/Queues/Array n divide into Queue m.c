#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the number of queues: ");
    scanf("%d", &m);
    int *arr = (int *)malloc(n * sizeof(int));
    int *front = (int *)malloc(m * sizeof(int));
    int *rear = (int *)malloc(m * sizeof(int));
    int i, j;
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < m; i++) {
        front[i] = -1;
        rear[i] = -1;
    }
    i = 0;
    j = 0;
    while (i < n) {
        if (rear[j] == m-1 || i == n) {
            // Queue j is full or we have reached the end of the array
            j = (j + 1) % m;
        } else {
            if (front[j] == -1) {
                // Queue j is empty
                front[j] = 0;
            }
            rear[j] = (rear[j] + 1) % m;
            // Insert the element into queue j
            arr[rear[j]] = arr[i];
            i++;
        }
    }
    // Print the contents of the queues
    for (i = 0; i < m; i++) {
        printf("Queue %d: ", i+1);
        if (front[i] == -1) {
            printf("Empty");
        } else {
            for (j = front[i]; j <= rear[i]; j++) {
                printf("%d ", arr[j]);
            }
        }
        printf("\n");
    }
    free(arr);
    free(front);
    free(rear);
    return 0;
}
