#include <stdio.h>

// Define a structure for the min-max pair
typedef struct {
    int min;
    int max;
} MinMax;

// Recursive function to search for the minimum and maximum numbers in an array
MinMax search_min_max(int arr[], int start, int end) {
    MinMax minmax, left, right;
    int mid;
    if (start == end) {
        minmax.min = arr[start];
        minmax.max = arr[start];
        return minmax;
    }
    if (end == start + 1) {
        if (arr[start] > arr[end]) {
            minmax.max = arr[start];
            minmax.min = arr[end];
        } else {
            minmax.max = arr[end];
            minmax.min = arr[start];
        }
        return minmax;
    }
    mid = (start + end) / 2;
    left = search_min_max(arr, start, mid);
    right = search_min_max(arr, mid + 1, end);
    if (left.min < right.min) {
        minmax.min = left.min;
    } else {
        minmax.min = right.min;
    }
    if (left.max > right.max) {
        minmax.max = left.max;
    } else {
        minmax.max = right.max;
    }
    return minmax;
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MinMax result = search_min_max(arr, 0, n - 1);
    printf("The minimum number is %d and the maximum number is %d\n", result.min, result.max);
    return 0;
}
