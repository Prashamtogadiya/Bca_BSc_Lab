#include <stdio.h>

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter numbers 1 : ");
    scanf("%d", &num1);
    printf("Enter numbers 2 : ");
    scanf("%d", &num2);


    // Check and display the largest number
    if (num1 > num2) {
        printf("The largest number is: %d\n", num1);
    } else if (num2 > num1) {
        printf("The largest number is: %d\n", num2);
    } else {
        printf("Both numbers are equal.\n");
    }

    return 0;
}
