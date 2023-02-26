#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Binary search with recursive function
int binary_search_recursive(Student arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid].id == target) {
        return mid;
    } else if (arr[mid].id > target) {
        return binary_search_recursive(arr, left, mid - 1, target);
    } else {
        return binary_search_recursive(arr, mid + 1, right, target);
    }
}

// Binary search without recursive function
int binary_search(Student arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].id == target) {
            return mid;
        } else if (arr[mid].id > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student arr[n];
    printf("Enter the student records (id, name, gpa):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &arr[i].id, arr[i].name, &arr[i].gpa);
    }
    int target;
    printf("Enter the student ID to search for: ");
    scanf("%d", &target);
    int index = binary_search_recursive(arr, 0, n - 1, target);
    if (index != -1) {
        printf("Student found at index %d: %d %s %.2f\n", index, arr[index].id, arr[index].name, arr[index].gpa);
    } else {
        printf("Student not found.\n");
    }
    index = binary_search(arr, n, target);
    if (index != -1) {
        printf("Student found at index %d: %d %s %.2f\n", index, arr[index].id, arr[index].name, arr[index].gpa);
    } else {
        printf("Student not found.\n");
    }
    return 0;
}
