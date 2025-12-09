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

// Insert into BST
struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    // if equal, ignore or handle duplicates as you like (here: ignore)

    return root;
}

// Inorder traversal (LNR) - gives sorted order
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

// Search in BST
struct Node* search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    struct Node *root = NULL;
    int choice, value, n, key, i;

    while (1) {
        printf("\n\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Create BST (Insert multiple nodes)\n");
        printf("2. Insert a single node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Search for a node\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many nodes do you want to insert? ");
                scanf("%d", &n);
                printf("Enter %d values:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 6:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Enter value to search: ");
                    scanf("%d", &key);
                    struct Node *found = search(root, key);
                    if (found != NULL)
                        printf("Node %d found in the tree.\n", key);
                    else
                        printf("Node %d NOT found in the tree.\n", key);
                }
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
