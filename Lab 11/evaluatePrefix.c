#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push an integer to the stack
void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

// Function to pop an integer from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to apply an operator to two operands
int applyOperator(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Cannot divide by zero\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Invalid operator: %c\n", operator);
            exit(1);
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char *expression) {
    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        char ch = expression[i];

        if (isdigit(ch)) {
            int num = 0;
            int factor = 1;

            // Handle multi-digit numbers
            while (i >= 0 && isdigit(expression[i])) {
                num += (expression[i] - '0') * factor;
                factor *= 10;
                i--;
            }
            i++;
            push(num);
        }
        else if (isOperator(ch)) {
            int operand1 = pop();
            int operand2 = pop();
            int result = applyOperator(ch, operand1, operand2);
            push(result);
        }
    }
    return pop();
}

int main() {
    char prefixExpression1[] = "+ 9 * 2 3";
    char prefixExpression2[] = "- + 8 6 / 4 2";
    char prefixExpression3[] = "* - 10 2 + 3 4";

    printf("Result of prefixExpression1: %d\n", evaluatePrefix(prefixExpression1)); // Output: 15
    printf("Result of prefixExpression2: %d\n", evaluatePrefix(prefixExpression2)); // Output: 12
    printf("Result of prefixExpression3: %d\n", evaluatePrefix(prefixExpression3)); // Output: 56

    return 0;
}
