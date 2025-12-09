#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char pan[20];              // PAN Number
    struct Employee *next;     // Pointer to next node
};

struct Employee *head = NULL;

// Create new node
struct Employee* createNode(char pan[]) {
    struct Employee *newNode = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(newNode->pan, pan);
    newNode->next = NULL;
    return newNode;
}

// Insert at any position (1-based)
void insertAtPosition(int position, char pan[]) {
    struct Employee *newNode = createNode(pan);

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

// Delete node by PAN number
void deleteNode(char pan[]) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Employee *temp = head;
    struct Employee *prev = NULL;

    if (strcmp(temp->pan, pan) == 0) {
        head = temp->next;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    while (temp != NULL && strcmp(temp->pan, pan) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("PAN not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted.\n");
}

// Search a node by PAN
void searchNode(char pan[]) {
    struct Employee *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->pan, pan) == 0) {
            printf("PAN Found: %s\n", temp->pan);
            return;
        }
        temp = temp->next;
    }

    printf("PAN not found.\n");
}

// Modify PAN Number
void modifyPAN(char oldPAN[], char newPAN[]) {
    struct Employee *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->pan, oldPAN) == 0) {
            strcpy(temp->pan, newPAN);
            printf("PAN updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("PAN not found.\n");
}

// Reverse Linked List
void reverseList() {
    struct Employee *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("Linked List reversed.\n");
}

// Print all PAN numbers
void printList() {
    struct Employee *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n--- PAN List ---\n");
    while (temp != NULL) {
        printf("%s\n", temp->pan);
        temp = temp->next;
    }
}

int main() {
    int choice, position;
    char pan[20], oldPAN[20], newPAN[20];

    while (1) {
        printf("\n\n----- MENU -----\n");
        printf("1. Insert PAN at Position\n");
        printf("2. Delete PAN\n");
        printf("3. Search PAN\n");
        printf("4. Reverse Linked List\n");
        printf("5. Modify PAN\n");
        printf("6. Print List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter PAN: ");
                scanf("%s", pan);
                insertAtPosition(position, pan);
                break;

            case 2:
                printf("Enter PAN to delete: ");
                scanf("%s", pan);
                deleteNode(pan);
                break;

            case 3:
                printf("Enter PAN to search: ");
                scanf("%s", pan);
                searchNode(pan);
                break;

            case 4:
                reverseList();
                break;

            case 5:
                printf("Enter old PAN: ");
                scanf("%s", oldPAN);
                printf("Enter new PAN: ");
                scanf("%s", newPAN);
                modifyPAN(oldPAN, newPAN);
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
