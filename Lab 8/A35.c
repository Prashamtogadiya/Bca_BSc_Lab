#include <stdio.h>

#define MAX_SIZE 100

// Stack data structure
int stack[MAX_SIZE];
int top = -1;

// Push element onto the stack
void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Change the nth element from the top of the stack
void change(int position_from_top, int new_value) {
    if (position_from_top > 0 && position_from_top <= (top + 1)) {
        int index = top - position_from_top + 1;
        stack[index] = new_value;
        printf("Changed %dth element from top to %d\n", position_from_top, new_value);
    } else {
        printf("Invalid position\n");
    }
}

// Peep the nth element from the top of the stack
int peep(int position_from_top) {
    if (position_from_top > 0 && position_from_top <= (top + 1)) {
        int index = top - position_from_top + 1;
        return stack[index];
    } else {
        printf("Invalid position\n");
        return -1;  // Error value
    }
}

// Display stack contents
void displayStack() {
    printf("Current Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    // Sample stack operations
    push(10);
    push(20);
    push(30);
    push(40);
    displayStack();

    // Peep 2nd element from top
    int value = peep(2);
    if (value != -1) {
        printf("Peeped 2nd element from top: %d\n", value);
    }

    // Change 3rd element from top to 99
    change(3, 99);
    displayStack();

    return 0;
}
