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
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    
    printf("Linked List: ");
    displayList(head);
    
    int value;
    printf("Enter the value to search: ");
    scanf("%d", &value);
    
    int position = searchNode(head, value);
    if (position != -1) {
        printf("Value %d found at position %d.\n", value, position);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
    
    return 0;
}
