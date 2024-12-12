#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], min = arr[0], sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
        if (arr[i] < min) min = arr[i];
        sum += arr[i];
    }

    double average = (double)sum / n;
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
