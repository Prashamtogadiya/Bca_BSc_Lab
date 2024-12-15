#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to enqueue an element to the queue
void enqueue(int value) {
    // Check if the queue is full
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }

    // If the queue is empty, initialize front
    if (front == -1) {
        front = 0;
    }

    // Increment the rear and enqueue the element
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from the queue
void dequeue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    // Dequeue the element and move the front pointer
    printf("Dequeued: %d\n", queue[front]);
    front++;

    // Reset the queue if it becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

// Function to display elements in the queue
void display() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    // Display the elements from front to rear
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
