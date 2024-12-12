// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int front, rear, size;
//     int* queue;
// } Deque;

// // Function to initialize the deque with the given size
// Deque* initializeDeque(int size) {
//     Deque* dq = (Deque*)malloc(sizeof(Deque));
//     dq->front = dq->rear = -1;
//     dq->size = size;
//     dq->queue = (int*)malloc(size * sizeof(int));
//     return dq;
// }

// // Function to check if the deque is full
// int isFull(Deque* dq) {
//     return (dq->rear + 1) % dq->size == dq->front;
// }

// // Function to check if the deque is empty
// int isEmpty(Deque* dq) {
//     return dq->front == -1;
// }

// // Function to insert an element at the rear of the deque
// void insertRear(Deque* dq, int value) {
//     if (isFull(dq)) {
//         printf("Deque Overflow\n");
//         return;
//     }
//     if (isEmpty(dq)) {
//         dq->front = dq->rear = 0;
//     } else {
//         dq->rear = (dq->rear + 1) % dq->size;
//     }
//     dq->queue[dq->rear] = value;
//     printf("Inserted %d at rear\n", value);
// }

// // Function to delete an element from the front of the deque
// int deleteFront(Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque Underflow\n");
//         return -1;
//     }
//     int value = dq->queue[dq->front];
//     if (dq->front == dq->rear) {
//         dq->front = dq->rear = -1;
//     } else {
//         dq->front = (dq->front + 1) % dq->size;
//     }
//     printf("Deleted %d from front\n", value);
//     return value;
// }

// // Function to insert an element at the front of the deque
// void insertFront(Deque* dq, int value) {
//     if (isFull(dq)) {
//         printf("Deque Overflow\n");
//         return;
//     }
//     if (isEmpty(dq)) {
//         dq->front = dq->rear = 0;
//     } else {
//         dq->front = (dq->front - 1 + dq->size) % dq->size;
//     }
//     dq->queue[dq->front] = value;
//     printf("Inserted %d at front\n", value);
// }

// // Function to delete an element from the rear of the deque
// int deleteRear(Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque Underflow\n");
//         return -1;
//     }
//     int value = dq->queue[dq->rear];
//     if (dq->front == dq->rear) {
//         dq->front = dq->rear = -1;
//     } else {
//         dq->rear = (dq->rear - 1 + dq->size) % dq->size;
//     }
//     printf("Deleted %d from rear\n", value);
//     return value;
// }

// // Function to display the elements of the deque
// void displayDeque(Deque* dq) {
//     if (isEmpty(dq)) {
//         printf("Deque is Empty\n");
//         return;
//     }
//     printf("Deque elements: ");
//     int i = dq->front;
//     while (i != dq->rear) {
//         printf("%d ", dq->queue[i]);
//         i = (i + 1) % dq->size;
//     }
//     printf("%d\n", dq->queue[dq->rear]);
// }

// // Main function to interact with the deque
// int main() {
//     int size, choice, value;
//     printf("Enter the size of the deque: ");
//     scanf("%d", &size);

//     Deque* dq = initializeDeque(size);
//     int running = 1;

//     while (running) {
//         printf("\nEnter\n1 for Insert Rear\n2 for Delete Front\n3 for Insert Front\n4 for Delete Rear\n5 for Display\n6 for Stop\n");
//         printf("Your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter an element to insert at rear: ");
//                 scanf("%d", &value);
//                 insertRear(dq, value);
//                 displayDeque(dq);
//                 break;
//             case 2:
//                 deleteFront(dq);
//                 displayDeque(dq);
//                 break;
//             case 3:
//                 printf("Enter an element to insert at front: ");
//                 scanf("%d", &value);
//                 insertFront(dq, value);
//                 displayDeque(dq);
//                 break;
//             case 4:
//                 deleteRear(dq);
//                 displayDeque(dq);
//                 break;
//             case 5:
//                 displayDeque(dq);
//                 break;
//             case 6:
//                 running = 0;
//                 break;
//             default:
//                 printf("Invalid Choice\n");
//         }
//     }

//     // Free allocated memory for the deque
//     free(dq->queue);
//     free(dq);
    
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // Define the maximum size of the deque

int deque[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the deque is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the deque is empty
int isEmpty() {
    return front == -1;
}

// Function to insert an element at the rear of the deque
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Function to delete an element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) {  // Reset if deque becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to insert an element at the front of the deque
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

// Function to delete an element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) {  // Reset if deque becomes empty
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
}

// Function to display the elements of the deque
void displayDeque() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;
    int running = 1;

    while (running) {
        printf("\nEnter\n1 for Insert Rear\n2 for Delete Front\n3 for Insert Front\n4 for Delete Rear\n5 for Display\n6 for Stop\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                displayDeque();
                break;
            case 2:
                deleteFront();
                displayDeque();
                break;
            case 3:
                printf("Enter an element to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                displayDeque();
                break;
            case 4:
                deleteRear();
                displayDeque();
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
