#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Inorder Traversal (LNR)
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find minimum element in BST
int findMin(struct Node *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Find maximum element in BST
int findMax(struct Node *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Insert Node (Create BST)\n");
        printf("2. Inorder Traversal\n");
        printf("3. Display Minimum Element\n");
        printf("4. Display Maximum Element\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                value = findMin(root);
                if (value != -1)
                    printf("Minimum element in BST: %d\n", value);
                break;

            case 4:
                value = findMax(root);
                if (value != -1)
                    printf("Maximum element in BST: %d\n", value);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
