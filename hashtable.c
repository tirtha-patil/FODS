#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[SIZE];

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert key using linear probing
void insert(int key) {
    int index = hash(key);
    int i, h;

    for (i = 0; i < SIZE; i++) {
        h = (index + i) % SIZE;

        if (hashTable[h] == EMPTY || hashTable[h] == DELETED) {
            hashTable[h] = key;
            printf("Inserted %d at index %d\n", key, h);
            return;
        }
    }
    printf("Hash Table is full! Cannot insert.\n");
}

// Search for a key
void search(int key) {
    int index = hash(key);
    int i, h;

    for (i = 0; i < SIZE; i++) {
        h = (index + i) % SIZE;

        if (hashTable[h] == key) {
            printf("Key %d found at index %d\n", key, h);
            return;
        }

        if (hashTable[h] == EMPTY)
            break;  
    }

    printf("Key %d not found.\n", key);
}

// Delete a key
void delete(int key) {
    int index = hash(key);
    int i, h;

    for (i = 0; i < SIZE; i++) {
        h = (index + i) % SIZE;

        if (hashTable[h] == key) {
            hashTable[h] = DELETED;
            printf("Key %d deleted from index %d\n", key, h);
            return;
        }

        if (hashTable[h] == EMPTY)
            break;
    }

    printf("Key %d not found.\n", key);
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else if (hashTable[i] == DELETED)
            printf("Index %d: DELETED\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;

    // Initialize hash table with EMPTY
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;

    while (1) {
        printf("\n--- HASH TABLE MENU ---\n");
        printf("1. Insert Key\n");
        printf("2. Search Key\n");
        printf("3. Delete Key\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(key);
            break;

        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            delete(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
