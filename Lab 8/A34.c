#include <stdio.h>

#define MAX_SIZE 5

// Stack data structure
int stack[MAX_SIZE] = {15, 75, 14, 28};  // Stack initialized with the given elements
int top = 3;  // Current top of the stack (index 3), stack size is 5

// Function to display the current state of the stack
void displayStack() {
    printf("Current Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
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

int main() {
    displayStack();
    
    // a. Change 4th element from top to 46
    change(4, 46);
    displayStack();

    // b. Peep: 3rd element from top
    int third_from_top = peep(3);
    if (third_from_top != -1) {
        printf("Peeped 3rd element from top: %d\n", third_from_top);
    }

    // c. Change 2nd element from top to 95
    change(2, 95);
    displayStack();

    // d. Peep: 2nd element from top
    int second_from_top = peep(2);
    if (second_from_top != -1) {
        printf("Peeped 2nd element from top: %d\n", second_from_top);
    }

    return 0;
}
