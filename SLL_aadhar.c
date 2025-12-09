#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char aadhar[20];             // Aadhar number
    struct Employee *next;       // Pointer to next node
};

struct Employee *head = NULL;

// Create a new node
struct Employee* createNode(char aadhar[]) {
    struct Employee *newNode = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(newNode->aadhar, aadhar);
    newNode->next = NULL;
    return newNode;
}

// Insert at any position (1-based index)
void insertAtPosition(int position, char aadhar[]) {
    struct Employee *newNode = createNode(aadhar);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Employee *temp = head;
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
    temp->next = newNode;
}

// Delete node by Aadhar number
void deleteNode(char aadhar[]) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Employee *temp = head;
    struct Employee *prev = NULL;

    if (strcmp(temp->aadhar, aadhar) == 0) {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    while (temp != NULL && strcmp(temp->aadhar, aadhar) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Aadhar number not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");
}

// Search a node by Aadhar
void searchNode(char aadhar[]) {
    struct Employee *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->aadhar, aadhar) == 0) {
            printf("Aadhar found: %s\n", temp->aadhar);
            return;
        }
        temp = temp->next;
    }

    printf("Aadhar not found.\n");
}

// Modify Aadhar number
void modifyAadhar(char oldAadhar[], char newAadhar[]) {
    struct Employee *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->aadhar, oldAadhar) == 0) {
            strcpy(temp->aadhar, newAadhar);
            printf("Aadhar updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Aadhar not found.\n");
}

// Reverse linked list
void reverseList() {
    struct Employee *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("Linked list reversed.\n");
}

// Print list
void printList() {
    struct Employee *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n--- Aadhar List ---\n");
    while (temp != NULL) {
        printf("%s\n", temp->aadhar);
        temp = temp->next;
    }
}

int main() {
    int choice, position;
    char aadhar[20], oldAadhar[20], newAadhar[20];

    while (1) {
        printf("\n\n----- MENU -----\n");
        printf("1. Insert Aadhar at Position\n");
        printf("2. Delete Aadhar\n");
        printf("3. Search Aadhar\n");
        printf("4. Reverse Linked List\n");
        printf("5. Modify Aadhar Number\n");
        printf("6. Print List\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter Aadhar number: ");
                scanf("%s", aadhar);
                insertAtPosition(position, aadhar);
                break;

            case 2:
                printf("Enter Aadhar number to delete: ");
                scanf("%s", aadhar);
                deleteNode(aadhar);
                break;

            case 3:
                printf("Enter Aadhar number to search: ");
                scanf("%s", aadhar);
                searchNode(aadhar);
                break;

            case 4:
                reverseList();
                break;

            case 5:
                printf("Enter old Aadhar number: ");
                scanf("%s", oldAadhar);
                printf("Enter new Aadhar number: ");
                scanf("%s", newAadhar);
                modifyAadhar(oldAadhar, newAadhar);
                break;

            case 6:
                printList();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
