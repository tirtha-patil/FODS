#include <stdio.h>
#include <string.h>

#define MAX 50

// Binary Search for sorted array of words
int binarySearch(char arr[][MAX], int size, char target[]) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0)
            return mid;  // Found the target
        else if (cmp < 0)
            low = mid + 1;  // Search right half
        else
            high = mid - 1; // Search left half
    }
    return -1;  // Not found
}

// Linear search for unsorted array of words
int linearSearch(char arr[][MAX], int size, char target[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0)
            return i;
    }
    return -1;
}

int main() {
    char sortedArr[][MAX] = {"apple", "banana", "cat", "dog", "mango", "zebra"};
    char unsortedArr[][MAX] = {"dog", "apple", "zebra", "cat", "mango", "banana"};

    int size = 6;
    char target[MAX];

    printf("Enter the word to search: ");
    scanf("%s", target);

    int sortedIndex = binarySearch(sortedArr, size, target);
    int unsortedIndex = linearSearch(unsortedArr, size, target);

    printf("\n--- Search Results ---\n");

    if (sortedIndex != -1)
        printf("Binary Search (sorted array): Found at index %d\n", sortedIndex);
    else
        printf("Binary Search (sorted array): Not found (-1)\n");

    if (unsortedIndex != -1)
        printf("Linear Search (unsorted array): Found at index %d\n", unsortedIndex);
    else
        printf("Linear Search (unsorted array): Not found (-1)\n");

    return 0;
}
