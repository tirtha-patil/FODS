#include <stdio.h>

#define SIZE 50

// Function to check if array is already sorted (descending)
int isSortedDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1])
            return 0;  // Not sorted
    }
    return 1;  // Already sorted
}

// Bubble Sort with early termination
void bubbleSort(int arr[], int n) {
    if (isSortedDescending(arr, n)) {
        printf("\nArray already sorted (Descending). Bubble Sort terminated early.\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

// Selection Sort with early termination
void selectionSort(int arr[], int n) {
    if (isSortedDescending(arr, n)) {
        printf("\nArray already sorted (Descending). Selection Sort terminated early.\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

// Insertion Sort with early termination
void insertionSort(int arr[], int n) {
    if (isSortedDescending(arr, n)) {
        printf("\nArray already sorted (Descending). Insertion Sort terminated early.\n");
        return;
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Print array
void printArray(int arr[], int n) {
    printf("\nArray: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Copy array for using each sort separately
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int arr[SIZE], n;

    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int arrBubble[SIZE], arrSelection[SIZE], arrInsertion[SIZE];

    copyArray(arr, arrBubble, n);
    copyArray(arr, arrSelection, n);
    copyArray(arr, arrInsertion, n);

    printf("\n--- Bubble Sort (Descending) ---");
    bubbleSort(arrBubble, n);
    printArray(arrBubble, n);

    printf("\n--- Selection Sort (Descending) ---");
    selectionSort(arrSelection, n);
    printArray(arrSelection, n);

    printf("\n--- Insertion Sort (Descending) ---");
    insertionSort(arrInsertion, n);
    printArray(arrInsertion, n);

    return 0;
}
