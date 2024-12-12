#include <stdio.h>

int main() {
    int n, count = 0;

    // Input the size of the array
    printf("Enter Size Of Array: ");
    scanf("%d", &n);

    // Declare the array
    int a[n];

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        printf("Insert Element: ");
        scanf("%d", &a[i]);
    }

    // Bubble Sort
    int last = n - 1;
    for (int i = 0; i < n - 1; i++) {   // Outer loop for passes
        int swapped = 0;
        for (int j = 0; j < last; j++) {  // Inner loop for comparisons
            if (a[j] > a[j + 1]) {
                // Swap elements
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;  // Mark that a swap occurred
                count++;
            }
        }
        last--;  // Reduce the range for the next pass
        if (!swapped) {  // If no swap happened in this pass, the array is sorted
            printf("Already Sorted\n");
            return 0;  // Exit early
        }
    }

    // Display the sorted array
    printf("Complete\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
