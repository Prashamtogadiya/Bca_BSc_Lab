// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int front, rear, size;
//     int* queue;
// } CircularQueue;

// // Function to initialize the circular queue with the given size
// CircularQueue* initializeQueue(int size) {
//     CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
//     cq->front = cq->rear = -1;
//     cq->size = size;
//     cq->queue = (int*)malloc(size * sizeof(int));
//     return cq;
// }

// // Function to check if the circular queue is full
// int isFull(CircularQueue* cq) {
//     return (cq->rear + 1) % cq->size == cq->front;
// }

// // Function to check if the circular queue is empty
// int isEmpty(CircularQueue* cq) {
//     return cq->front == -1;
// }

// // Function to enqueue an element into the circular queue
// void enqueue(CircularQueue* cq, int value) {
//     if (isFull(cq)) {
//         printf("Circular Queue Overflow\n");
//         return;
//     }
//     if (isEmpty(cq)) {
//         cq->front = 0;
//     }
//     cq->rear = (cq->rear + 1) % cq->size;
//     cq->queue[cq->rear] = value;
//     printf("Enqueued: %d\n", value);
// }

// // Function to dequeue an element from the circular queue
// int dequeue(CircularQueue* cq) {
//     if (isEmpty(cq)) {
//         printf("Circular Queue Underflow\n");
//         return -1;
//     }
//     int dequeuedValue = cq->queue[cq->front];
//     if (cq->front == cq->rear) {  // Reset if the queue becomes empty
//         cq->front = cq->rear = -1;
//     } else {
//         cq->front = (cq->front + 1) % cq->size;
//     }
//     printf("Dequeued: %d\n", dequeuedValue);
//     return dequeuedValue;
// }

// // Function to display the elements in the circular queue
// void displayQueue(CircularQueue* cq) {
//     if (isEmpty(cq)) {
//         printf("Queue is Empty\n");
//         return;
//     }
//     printf("Queue elements: ");
//     int i = cq->front;
//     do {
//         printf("%d ", cq->queue[i]);
//         i = (i + 1) % cq->size;
//     } while (i != (cq->rear + 1) % cq->size);
//     printf("\n");
// }

// // Main function to interact with the circular queue
// int main() {
//     int size, choice, value;
//     printf("Enter the size of the circular queue: ");
//     scanf("%d", &size);

//     CircularQueue* cq = initializeQueue(size);
//     int running = 1;

//     while (running) {
//         printf("\nEnter\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Stop\n");
//         printf("Your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter an element to enqueue: ");
//                 scanf("%d", &value);
//                 enqueue(cq, value);
//                 displayQueue(cq);
//                 break;
//             case 2:
//                 dequeue(cq);
//                 displayQueue(cq);
//                 break;
//             case 3:
//                 displayQueue(cq);
//                 break;
//             case 4:
//                 running = 0;
//                 break;
//             default:
//                 printf("Invalid Choice\n");
//         }
//     }

//     // Free allocated memory for the circular queue
//     free(cq->queue);
//     free(cq);
    
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    // Logic to check if the queue is full
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Circular Queue is full! Cannot enqueue %d.\n", value);
        return;
    }

    // Logic for enqueue operation
    if (front == -1 && rear == -1) {
        front = rear = 0; // Initialize front and rear for first element
    } else {
        rear = (rear + 1) % MAX_SIZE; // Move rear circularly
    }

    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    // Logic to check if the queue is empty
    if (front == -1) {
        printf("Circular Queue is empty! Cannot dequeue.\n");
        return;
    }

    // Logic for dequeue operation
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Reset queue if it becomes empty
    } else {
        front = (front + 1) % MAX_SIZE; // Move front circularly
    }
}

void display() {
    // Logic to check if the queue is empty
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE; // Move circularly
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
