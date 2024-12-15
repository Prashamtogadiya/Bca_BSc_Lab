#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        printf("Node with value %d inserted at the end.\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node with value %d inserted at the end.\n", data);
}

// Function to search for a node with a specific value
int searchNode(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            return position;  // Return position if value is found
        }
        temp = temp->next;
        position++;
    }
    return -1;  // Return -1 if value is not found
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Search for a value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                int position = searchNode(head, value);
                if (position != -1) {
                    printf("Value %d found at position %d.\n", value, position);
                } else {
                    printf("Value %d not found in the list.\n", value);
                }
                break;

            case 3:
                printf("Current linked list:\n");
                displayList(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
