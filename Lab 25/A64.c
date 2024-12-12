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

    // Insertion Sort
    int k = 0;
    while (k < n) {
        int key = a[k];
        int j = k - 1;

        // Shift elements greater than 'key' to the right
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        k++;
    }

    // Display the sorted array
    printf("Complete\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
