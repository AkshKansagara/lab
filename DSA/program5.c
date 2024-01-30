#include <stdio.h>

#define MAX_SIZE 100  // Maximum array size

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap elements at indices i and j:
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot element with element at index i + 1:
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
