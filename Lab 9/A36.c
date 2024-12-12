#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure and functions
char stack[MAX_SIZE];
int top = -1;

// Push element to stack
void push(char ch) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = ch;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop element from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

// Peek at the top element of the stack
char peek() {
    return stack[top];
}

// Function G: "incoming" precedence
int G(char next) {
    if (next == '+' || next == '-') {
        return 2;
    } else if (next == '*' || next == '/') {
        return 4;
    } else if (next == '^') {
        return 5;
    } else if (isalpha(next) || isdigit(next)) {
        return 8;  // Higher precedence for operands
    } else if (next == '(') {
        return 0;
    }
    return -1;
}

// Function F: "stack" precedence
int F(char next) {
    if (next == '+' || next == '-') {
        return 1;
    } else if (next == '*' || next == '/') {
        return 3;
    } else if (next == '^') {
        return 6;
    } else if (isalpha(next) || isdigit(next)) {
        return 7;
    } else if (next == '(') {
        return 9;
    } else if (next == ')') {
        return 0;
    }
    return -1;
}

// Convert infix to postfix notation
char* infixToPostfix(char* infix) {
    static char postfix[MAX_SIZE];
    int i = 0, j = 0;
    int rank = 0;

    push('(');  // Initial '(' to signify the beginning of the expression
    strcat(infix, ")");  // Append ')' to signify the end of the expression

    while (infix[i] != '\0') {
        char next = infix[i];
        
        // If stack becomes empty before processing completes, expression is invalid
        if (top == -1) {
            printf("Infix expression is invalid.\n");
            return NULL;
        }

        // Operand (letter or digit), add to postfix
        if (isalnum(next)) {
            postfix[j++] = next;
            rank++;
            if (rank >= 2) {  // Rank mismatch check
                printf("Infix is invalid -- rank does not match\n");
                return NULL;
            }
        }
        // Operator, handle precedence and associativity
        else if (next == '+' || next == '-' || next == '*' || next == '/') {
            while (G(peek()) > F(next)) {
                postfix[j++] = pop();
                rank--;
                if (rank < 1) {
                    printf("Infix is invalid -- rank does not match\n");
                    return NULL;
                }
            }
            push(next);
            rank--;
        }
        // Exponentiation operator
        else if (next == '^') {
            push(next);
        }
        // Left parenthesis, push to stack
        else if (next == '(') {
            push(next);
        }
        // Right parenthesis, pop until left parenthesis
        else if (next == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop the '(' from stack
        }
        i++;
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
    return postfix;
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0;  // Remove newline character from input

    char* postfix = infixToPostfix(infix);
    if (postfix) {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}
