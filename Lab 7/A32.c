#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;
//review step as per algo

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
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // a. Push: 15, 75, 32
    push(15);
    push(75);
    push(32);

    // b. Pop
    pop();

    // c. Push: 14, 16
    push(14);
    push(16);

    // d. Display
    display();

    // e. Pop
    pop();

    // f. Push: 28, 39, 49
    push(28);
    push(39);
    push(49);

    // g. Display
    display();

    return 0;
}
