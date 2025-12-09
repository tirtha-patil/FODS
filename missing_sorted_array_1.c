#include <stdio.h>

int findSmallestMissingPositive(int arr[], int size) {
    int expected = 1;  // The smallest positive integer we expect

    for (int i = 0; i < size; i++) {
        if (arr[i] == expected) {
            expected++;    // Found the expected number, move to next
        }
        else if (arr[i] > expected) {
            // We found a gap
            return expected;
        }
        // If arr[i] < expected, ignore since negatives/zeros don't matter
    }

    // If no gap found, next number is the smallest missing
    return expected;
}

int main() {
    int arr[] = {-4, -2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing = findSmallestMissingPositive(arr, size);

    printf("Smallest missing positive integer: %d\n", missing);

    return 0;
}
