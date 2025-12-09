#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int age;
    struct Student *next;
    struct Student *prev;
};

struct Student *head = NULL;

// Create node
struct Student* createNode(char name[], int roll, int age) {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newNode->name, name);
    newNode->roll = roll;
    newNode->age = age;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at any position (1-based index)
void insertAtPosition(int position, char name[], int roll, int age) {
    struct Student *newNode = createNode(name, roll, age);

    if (position == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    struct Student *temp = head;
    int i = 1;

    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete node by roll number
void deleteNode(int roll) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Student *temp = head;

    while (temp != NULL && temp->roll != roll)
        temp = temp->next;

    if (temp == NULL) {
        printf("Roll number not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted.\n");
}

// Search a node
void searchNode(int roll) {
    struct Student *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("\nRecord Found:\n");
            printf("Name: %s\n", temp->name);
            printf("Roll: %d\n", temp->roll);
            printf("Age: %d\n", temp->age);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

// Modify roll number
void modifyRoll(int oldRoll, int newRoll) {
    struct Student *temp = head;

    while (temp != NULL) {
        if (temp->roll == oldRoll) {
            temp->roll = newRoll;
            printf("Roll number updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Roll number not found.\n");
}

// Print list forward
void printList() {
    struct Student *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("Name: %s | Roll: %d | Age: %d\n", temp->name, temp->roll, temp->age);
        temp = temp->next;
    }
}

int main() {
    int choice, position, roll, age, newRoll;
    char name[50];

    while (1) {
        printf("\n\n----- MENU -----\n");
        printf("1. Insert at Position\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Modify Roll Number\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter position: ");
            scanf("%d", &position);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter roll no: ");
            scanf("%d", &roll);
            printf("Enter age: ");
            scanf("%d", &age);
            insertAtPosition(position, name, roll, age);
            break;

        case 2:
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);
            deleteNode(roll);
            break;

        case 3:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            searchNode(roll);
            break;

        case 4:
            printf("Enter old roll number: ");
            scanf("%d", &roll);
            printf("Enter new roll number: ");
            scanf("%d", &newRoll);
            modifyRoll(roll, newRoll);
            break;

        case 5:
            printList();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
