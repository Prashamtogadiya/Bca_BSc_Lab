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
}

// Function to display the linked list
void displayList(struct Node* head) {
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
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    
    printf("Original List: ");
    displayList(head);
    
    int position = 2;
    deleteAtPosition(&head, position);
    printf("After deleting node at position %d: ", position);
    displayList(head);
    
    return 0;
}
