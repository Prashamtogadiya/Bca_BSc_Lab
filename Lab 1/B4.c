#include <stdio.h>

int main() {
    int marks[5];
    int sum = 0;
    float percentage;
    
    // Input marks of five subjects
    printf("Enter marks of five subjects (out of 100):\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }

    // Calculate percentage
    percentage = (sum / 5.0);

    // Print percentage
    printf("Percentage: %.2f%%\n", percentage);

    // Determine and print class based on percentage
    if (percentage < 35) {
        printf("Result: Fail\n");
    } else if (percentage >= 35 && percentage < 45) {
        printf("Result: Pass Class\n");
    } else if (percentage >= 45 && percentage < 60) {
        printf("Result: Second Class\n");
    } else if (percentage >= 60 && percentage < 70) {
        printf("Result: First Class\n");
    } else if (percentage >= 70) {
        printf("Result: Distinction\n");
    }

    return 0;
}
