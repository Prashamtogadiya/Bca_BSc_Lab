#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;
// as per algo review
// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to enqueue an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;
    if (front > rear) {  // Reset queue when it becomes empty
        front = rear = -1;
    }
}

// Function to display elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Perform operations as described
    // a. Enqueue: 15, 75, 32
    enqueue(15);
    enqueue(75);
    enqueue(32);

    // b. Dequeue
    dequeue();

    // c. Enqueue: 14, 16
    enqueue(14);
    enqueue(16);

    // d. Display
    display();

    // e. Dequeue
    dequeue();

    // f. Enqueue: 28, 39, 46
    enqueue(28);
    enqueue(39);
    enqueue(46);

    // g. Display
    display();

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int front, rear, size;
//     int* queue;
// } Queue;

// // Function to initialize the queue with given size
// Queue* initializeQueue(int size) {
//     Queue* q = (Queue*)malloc(sizeof(Queue));
//     q->front = q->rear = -1;
//     q->size = size;
//     q->queue = (int*)malloc(size * sizeof(int));
//     return q;
// }

// // Function to check if the queue is empty
// int isEmpty(Queue* q) {
//     return q->front == -1;
// }

// // Function to check if the queue is full
// int isFull(Queue* q) {
//     return q->rear == q->size - 1;
// }

// // Function to enqueue an element into the queue
// void enqueue(Queue* q, int value) {
//     if (isFull(q)) {
//         printf("Queue Overflow\n");
//         return;
//     }
//     if (isEmpty(q)) {
//         q->front = 0;
//     }
//     q->rear++;
//     q->queue[q->rear] = value;
//     printf("Enqueued: %d\n", value);
// }

// // Function to dequeue an element from the queue
// int dequeue(Queue* q) {
//     if (isEmpty(q)) {
//         printf("Queue Underflow\n");
//         return -1;
//     }
//     int dequeuedValue = q->queue[q->front];
//     if (q->front == q->rear) {  // Reset if the queue becomes empty
//         q->front = q->rear = -1;
//     } else {
//         q->front++;
//     }
//     printf("Dequeued: %d\n", dequeuedValue);
//     return dequeuedValue;
// }

// // Function to display the elements in the queue
// void displayQueue(Queue* q) {
//     if (isEmpty(q)) {
//         printf("Queue is Empty\n");
//         return;
//     }
//     printf("Queue elements: ");
//     for (int i = q->front; i <= q->rear; i++) {
//         printf("%d ", q->queue[i]);
//     }
//     printf("\n");
// }

// // Main function to interact with the queue
// int main() {
//     int size, choice, value;
//     printf("Enter the size of the queue: ");
//     scanf("%d", &size);

//     Queue* q = initializeQueue(size);
//     int running = 1;

//     while (running) {
//         printf("\nEnter\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Stop\n");
//         printf("Your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter an element to enqueue: ");
//                 scanf("%d", &value);
//                 enqueue(q, value);
//                 displayQueue(q);
//                 break;
//             case 2:
//                 dequeue(q);
//                 displayQueue(q);
//                 break;
//             case 3:
//                 displayQueue(q);
//                 break;
//             case 4:
//                 running = 0;
//                 break;
//             default:
//                 printf("Invalid Choice\n");
//         }
//     }

//     // Free allocated memory for the queue
//     free(q->queue);
//     free(q);
    
//     return 0;
// }
