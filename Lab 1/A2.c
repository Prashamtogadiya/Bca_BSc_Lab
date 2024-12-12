#include <stdio.h>

int main() {
    int num1, num2, num3;

    // Input three numbers
    printf("Enter numbers 1 : ");
    scanf("%d", &num1);
    printf("Enter numbers 2 : ");
    scanf("%d", &num2);
    printf("Enter numbers 3 : ");
    scanf("%d", &num3);

    // Check and display the largest number
    //nested if pending
    if (num1 >= num2 && num1 >= num3) {
        printf("The largest number is: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("The largest number is: %d\n", num2);
    } else {
        printf("The largest number is: %d\n", num3);
    }

    return 0;
}
