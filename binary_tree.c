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

// Create binary tree recursively
struct Node* createTree() {
    int value;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node *root = createNode(value);

    printf("Enter left child of %d:\n", value);
    root->left = createTree();

    printf("Enter right child of %d:\n", value);
    root->right = createTree();

    return root;
}

// Inorder traversal (LNR)
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (NLR)
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (LRN)
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;
    int choice;

    while (1) {
        printf("\n\n--- BINARY TREE MENU ---\n");
        printf("1. Create Binary Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nStart creating tree:\n");
                root = createTree();
                break;

            case 2:
                if (root == NULL)
                    printf("Tree not created yet.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                }
                printf("\n");
                break;

            case 3:
                if (root == NULL)
                    printf("Tree not created yet.\n");
                else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                }
                printf("\n");
                break;

            case 4:
                if (root == NULL)
                    printf("Tree not created yet.\n");
                else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                }
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
