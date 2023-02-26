#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

// Recursive function for Fibonacci search
int fibonacci_search_recursive(Employee arr[], int n, int target, int offset, int fib_k_2, int fib_k_1) {
    if (fib_k_1 <= 1) {
        int mid = offset + fib_k_2;
        if (mid >= n || arr[mid].id > target) {
            return -1;
        } else if (arr[mid].id < target) {
            return fibonacci_search_recursive(arr, n, target, mid + 1, fib_k_1 - fib_k_2, fib_k_2);
        } else {
            return mid;
        }
    }
    int mid = offset + fib_k_2;
    if (arr[mid].id == target) {
        return mid;
    } else if (arr[mid].id > target) {
        return fibonacci_search_recursive(arr, n, target, offset, fib_k_2 - fib_k_1, fib_k_1);
    } else {
        return fibonacci_search_recursive(arr, n, target, mid + 1, fib_k_1, fib_k_2 - fib_k_1);
    }
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
    int index = fibonacci_search_recursive(arr, n, target, 0, 0, 1);
    if (index != -1) {
        printf("Employee found at index %d: %d %s %.2f\n", index, arr[index].id, arr[index].name, arr[index].salary);
    } else {
        printf("Employee not found.\n");
    }
    return 0;
}
