#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

// Function for Fibonacci search
int fibonacci_search(Employee arr[], int n, int target) {
    int fib_k_2 = 0;
    int fib_k_1 = 1;
    int fib_k = fib_k_1 + fib_k_2;
    while (fib_k < n) {
        fib_k_2 = fib_k_1;
        fib_k_1 = fib_k;
        fib_k = fib_k_1 + fib_k_2;
    }
    int offset = 0;
    while (fib_k_1 > 0) {
        int i = offset + fib_k_2;
        if (i >= n || arr[i].id > target) {
            fib_k = fib_k_1;
            fib_k_1 = fib_k_2;
            fib_k_2 = fib_k - fib_k_1;
        } else if (arr[i].id < target) {
            offset = i + 1;
            fib_k = fib_k_2;
            fib_k_1 -= fib_k_2;
            fib_k_2 = fib_k - fib_k_1;
        } else {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    Employee arr[n];
    printf("Enter the employee records (id, name, salary):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &arr[i].id, arr[i].name, &arr[i].salary);
    }
    int target;
    printf("Enter the employee ID to search for: ");
    scanf("%d", &target);
    int index = fibonacci_search(arr, n, target);
    if (index != -1) {
        printf("Employee found at index %d: %d %s %.2f\n", index, arr[index].id, arr[index].name, arr[index].salary);
    } else {
        printf("Employee not found.\n");
    }
    return 0;
}
