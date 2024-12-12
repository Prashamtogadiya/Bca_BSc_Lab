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

// Function to insert a node at the end
void insertLast(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
    
    // a. Insert at first: 15, 75, 32
    insertFirst(&head, 15);
    insertFirst(&head, 75);
    insertFirst(&head, 32);
    
    // b. Display
    printf("List after insertions at first:\n");
    displayList(head);
    
    // c. Insert at last: 78, 37, 28
    insertLast(&head, 78);
    insertLast(&head, 37);
    insertLast(&head, 28);
    
    // d. Display
    printf("List after insertions at last:\n");
    displayList(head);

    return 0;
}
