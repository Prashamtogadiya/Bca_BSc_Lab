#include <stdio.h>

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

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

    // Perform Merge Sort
    mergeSort(a, 0, n - 1);

    // Display the sorted array
    printf("Sorting complete\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

// Merge Sort function
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        
        // Recursively divide the array into two halves
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        
        // Merge the sorted halves
        merge(a, low, mid, high);
    }
}

// Merge function to combine two sorted halves
void merge(int a[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        left[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = a[mid + 1 + j];
    }

    // Merge the temporary arrays back into a[]
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left[], if any
    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right[], if any
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
}
