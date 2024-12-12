#include <stdio.h>

int main() {
    int n, i, key;

    // Input the size of the array
    printf("Enter Size Of Array: ");
    scanf("%d", &n);

    // Declare the array
    int a[n];

    // Input elements into the array
    for (i = 0; i < n; i++) {
        printf("Insert Element at index %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("----------------------------\n");

    // Input the element to search for
    printf("Enter Element you want to search: ");
    scanf("%d", &key);

    // Linear Search
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Element found at index = %d\n", i);
            return 0;  // Exit the program if element is found
        }
    }

    // If element is not found
    printf("Element not found\n");

    return 0;
}
