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
    if (top >= 0)
        return stack[top];
    return '\0';
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
        return 8;
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

// Reverse the string and swap parentheses
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

// Convert infix to prefix notation
char* infixToPrefix(char* infix) {
    static char prefix[MAX_SIZE];
    int i = 0, j = 0;
    int rank = 0;

    reverse(infix);
    push('(');
    strcat(infix, ")");

    while (infix[i] != '\0') {
        char next = infix[i];
        
        if (top == -1) {
            printf("Infix expression is invalid.\n");
            return NULL;
        }

        if (isalnum(next)) {
            prefix[j++] = next;
            rank++;
        }
        else if (next == '+' || next == '-' || next == '*' || next == '/') {
            while (G(peek()) > F(next)) {
                rank--;
                prefix[j++] = pop();
                if (rank < 0) {
                    printf("Infix is invalid -- rank does not match\n");
                    return NULL;
                }
            }
            push(next);
            rank--;
        }
        else if (next == '^') {
            push(next);
        }
        else if (next == '(') {
            push(next);
        }
        else if (next == ')') {
            char temp2 = pop();
            while (temp2 != '(') {
                prefix[j++] = temp2;
                temp2 = pop();
            }
        }
        i++;
    }
    prefix[j] = '\0';

    // Reverse the result to get the final prefix expression
    reverse(prefix);
    return prefix;
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0;

    char* prefix = infixToPrefix(infix);
    if (prefix) {
        printf("Prefix expression: %s\n", prefix);
    }

    return 0;
}
