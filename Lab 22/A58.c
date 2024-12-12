#include <stdio.h>

int main() {
    int n, key, left, right, middle;

    // Input the size of the array
    printf("Enter Size Of Array: ");
    scanf("%d", &n);

    // Declare the array
    int a[n];

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        printf("Insert Element at index %d: ", i);
        scanf("%d", &a[i]);
    }

    // Sorting the array (Binary Search requires a sorted array)
    // Bubble sort to sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("----------------------------\n");

    // Input the element to search for
    printf("Enter Element you want to search: ");
    scanf("%d", &key);

    // Binary Search
    left = 0;
    right = n - 1;
    while (left <= right) {
        middle = (left + right) / 2;

        if (a[middle] == key) {
            printf("Element found at index = %d\n", middle);
            return 0;  // Exit the program if element is found
        }
        else if (key < a[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    // If element is not found
    printf("Element not found\n");

    return 0;
}
