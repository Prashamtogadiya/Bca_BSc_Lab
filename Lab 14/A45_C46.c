#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertFirst(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at a specified position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    // If the position is 1, insert at the beginning
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    // If the position is greater than the length of the list, insert at the end
    if (temp == NULL) {
        printf("Position is greater than the length of the list. Inserting at the end.\n");
        newNode->next = NULL;
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* last = *head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
        }
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
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
    
    // Insert at first
    insertFirst(&head, 15);
    insertFirst(&head, 75);
    insertFirst(&head, 32);
    
    // Display the list
    printf("List after insertions at first:\n");
    displayList(head);
    
    // Insert at specified position (2nd position)
    insertAtPosition(&head, 100, 2);
    
    // Display the list after insertion at position
    printf("List after insertion at position 2:\n");
    displayList(head);

    return 0;
}
