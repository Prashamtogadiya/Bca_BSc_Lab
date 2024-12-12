#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function declarations
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* delete(struct Node* root, int data);
struct Node* findMin(struct Node* root);
int search(struct Node* root, int data);
void inorder(struct Node* root);  // For testing

int main() {
    struct Node* root = NULL;
    int choice, data;
    int flag = 1;

    while (flag) {
        printf("\nEnter\n");
        printf("1 to insert Node\n");
        printf("2 to delete Node\n");
        printf("3 to search Node\n");
        printf("4 to Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("Node found.\n");
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice, please enter again.\n");
                break;
        }
    }

    // For testing purposes, let's print the tree in inorder
    printf("Inorder Traversal of the BST: ");
    inorder(root);
    printf("\n");

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function to insert a node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Delete function to delete a node in BST
struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

// Find minimum value node in the tree
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Search function to find a node in BST
int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0; // Node not found
    }
    if (root->data == data) {
        return 1; // Node found
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Inorder traversal for testing the BST structure
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
