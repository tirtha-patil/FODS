#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure to store student records
struct Student {
    char name[50];
    int roll;
    int age;
};

// Function to swap two records
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll > arr[j + 1].roll) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].roll < arr[minIndex].roll) {
                minIndex = j;
            }
        }
        if (minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(struct Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].roll > key.roll) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to print student records
void printRecords(struct Student arr[], int n) {
    printf("\nName\tRollNo\tAge\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", arr[i].name, arr[i].roll, arr[i].age);
    }
}

int main() {
    struct Student students[MAX];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll);
        printf("Age: ");
        scanf("%d", &students[i].age);
    }

    printf("\n--- Bubble Sort Result ---\n");
    bubbleSort(students, n);
    printRecords(students, n);

    // Re-enter records for fair comparison (optional for exams)
    // Or copy original array before sorting

    printf("\n--- Selection Sort Result ---\n");
    selectionSort(students, n);
    printRecords(students, n);

    printf("\n--- Insertion Sort Result ---\n");
    insertionSort(students, n);
    printRecords(students, n);

    return 0;
}
