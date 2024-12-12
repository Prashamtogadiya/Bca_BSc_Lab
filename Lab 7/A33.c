// #include <stdio.h>
// #include <stdlib.h>

// int *stack;  // Pointer for stack array
// int top = -1;
// int maxSize; // Variable to store stack size

// void push(int value) {
//     if (top == maxSize - 1) {
//         printf("Stack overflow! Cannot push %d.\n", value);
//     } else {
//         stack[++top] = value;
//         printf("Pushed %d to stack.\n", value);
//     }
// }

// void pop() {
//     if (top == -1) {
//         printf("Stack underflow! Cannot pop.\n");
//     } else {
//         printf("Popped %d from stack.\n", stack[top--]);
//     }
// }

// void display() {
//     if (top == -1) {
//         printf("Stack is empty.\n");
//     } else {
//         printf("Current stack elements: ");
//         for (int i = 0; i <= top; i++) {
//             printf("%d ", stack[i]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int choice, value;

//     printf("Enter the size of the stack: ");
//     scanf("%d", &maxSize);

//     // Dynamically allocate memory for stack based on the user-provided size
//     stack = (int *)malloc(maxSize * sizeof(int));
//     if (stack == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1; // Exit the program if memory allocation fails
//     }

//     while (1) {
//         printf("\nChoose an operation:\n");
//         printf("1. Push\n");
//         printf("2. Pop\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter value to push: ");
//                 scanf("%d", &value);
//                 push(value);
//                 break;
//             case 2:
//                 pop();
//                 break;
//             case 3:
//                 display();
//                 break;
//             case 4:
//                 printf("Exiting...\n");
//                 free(stack); // Free the allocated memory
//                 return 0;
//             default:
//                 printf("Invalid choice! Please try again.\n");
//         }
//     }
// }


#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow! Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d to stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow! Cannot pop.\n");
    } else {
        printf("Popped %d from stack.\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Current stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        // printf("");
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
