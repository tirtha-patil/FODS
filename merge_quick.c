#include <stdio.h>

#define SIZE 50

// Global counters for comparisons
long long mergeComparisons = 0;
long long quickComparisons = 0;

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge process
    while (i < n1 && j < n2) {
        mergeComparisons++; // Count comparison

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Partition for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quickComparisons++; // Count comparison

        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Print array
void printArray(int arr[], int n) {
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Copy array
void copyArray(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

int main() {
    int arr[SIZE], n;

    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int arrMerge[SIZE], arrQuick[SIZE];
    copyArray(arr, arrMerge, n);
    copyArray(arr, arrQuick, n);

    // Merge Sort
    mergeSort(arrMerge, 0, n - 1);
    printf("\n--- Merge Sort ---");
    printArray(arrMerge, n);
    printf("Merge Sort Comparisons: %lld\n", mergeComparisons);

    // Quick Sort
    quickSort(arrQuick, 0, n - 1);
    printf("\n--- Quick Sort ---");
    printArray(arrQuick, n);
    printf("Quick Sort Comparisons: %lld\n", quickComparisons);

    return 0;
}
