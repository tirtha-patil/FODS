int main() {
    int choice, roll, age, pos, newRoll, oldRoll;
    char name[50];

    while (1) {
        printf("\n\n----- MENU -----\n");
        printf("1. Insert at Position\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Reverse Linked List\n");
        printf("5. Modify Roll No\n");
        printf("6. Print List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter roll: ");
                scanf("%d", &roll);
                printf("Enter age: ");
                scanf("%d", &age);
                insertAtPosition(pos, name, roll, age);
                break;

            case 2:
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                deleteNode(roll);
                break;

            case 3:
                printf("Enter roll to search: ");
                scanf("%d", &roll);
                searchNode(roll);
                break;

            case 4:
                reverseList();
                break;

            case 5:
                printf("Enter old roll: ");
                scanf("%d", &oldRoll);
                printf("Enter new roll: ");
                scanf("%d", &newRoll);
                modifyRoll(oldRoll, newRoll);
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
