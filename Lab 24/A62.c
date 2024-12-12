#include <stdio.h>

int main() {
    int n;

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

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (min_index != i) {
            int temp = a[min_index];
            a[min_index] = a[i];
            a[i] = temp;
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
