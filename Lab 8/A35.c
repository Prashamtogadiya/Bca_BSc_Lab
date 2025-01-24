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
void change(int pos, int value) {
    if (top-pos+1<0) {
        printf("Invalid Position");
    } else {
        stack[top-pos+1]=value;
    }
}

// Peep the nth element from the top of the stack
int peep(int pos) {
    if (top-pos+1<0) {
        printf("Invalid Position");
    } else {
        return stack[top-pos+1];
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
    // if (value != -1) {
    //     printf("Peeped 2nd element from top: %d\n", value);
    // }

    // Change 3rd element from top to 99
    change(3, 99);
    displayStack();

    return 0;
}
