#include <stdio.h>

int main() {
    int num1, num2, choice;
    float result;

    // Input two numbers
    printf("Enter numbers 1 : ");
    scanf("%d", &num1);
    printf("Enter numbers 2 : ");
    scanf("%d", &num2);

    // Display the menu for operations
    printf("Choose an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Perform the operation based on the user's choice
    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("The result of addition is: %.2f\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result of subtraction is: %.2f\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result of multiplication is: %.2f\n", result);
            break;
        case 4:
            if (num2 != 0) {
                result = (float)num1 / num2;
                printf("The result of division is: %.2f\n", result);
            } else {
                printf("Error! Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
    }

    return 0;
}
