#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function declarations
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void preOrder(struct Node* root);
void inOrder(struct Node* root);
void postOrder(struct Node* root);

int main() {
    struct Node* root = NULL;
    int choice, data;
    int flag = 1;
    
    while (flag) {
        printf("\nEnter\n");
        printf("1 to insert Node\n");
        printf("2 to Preorder Traversal\n");
        printf("3 to Inorder Traversal\n");
        printf("4 to Postorder Traversal\n");
        printf("5 to exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                flag = 0;
                break;
            default:
                printf("Invalid choice, please enter again.\n");
                break;
        }
    }

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data in the BST
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

// Preorder Traversal
void preOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d-", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder Traversal
void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d-", root->data);
    inOrder(root->right);
}

// Postorder Traversal
void postOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d-", root->data);
}
