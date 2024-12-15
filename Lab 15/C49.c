#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node at a specified position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    if (position == 0) { // If head needs to be removed
        *head = temp->next;
        free(temp);
        printf("Node at position %d deleted successfully.\n", position);
        return;
    }
    
    // Find the node before the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node at position %d deleted successfully.\n", position);
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

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete at position\n");
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
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
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
