#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure for integer values
int stack[MAX_SIZE];
int top = -1;

// Push an element to the stack
void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return 0;
    }
}

// Check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Apply an operator to two operands
int applyOperator(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Cannot divide by zero\n");
                exit(1);
            }
            return operand1 / operand2;
    }
    return 0;
}

// Evaluate a postfix expression
int evaluatePostfix(char *expression) {
    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (i < strlen(expression) && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(num);
        } else if (isOperator(expression[i])) {
            int operand2 = pop();
            int operand1 = pop();
            int result = applyOperator(expression[i], operand1, operand2);
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char postfixExpression1[] = "5 6 2 + * 1 2 4 / - + ";
    char postfixExpression2[] = "8 6 + 4 2 / -";
    char postfixExpression3[] = "10 2 - 3 4 + *";

    printf("Result of postfixExpression1: %d\n", evaluatePostfix(postfixExpression1));
    printf("Result of postfixExpression2: %d\n", evaluatePostfix(postfixExpression2));
    printf("Result of postfixExpression3: %d\n", evaluatePostfix(postfixExpression3));

    return 0;
}
