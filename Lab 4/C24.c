#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += (i % 2 == 0) ? -i : i;
    }

    printf("Sum of series: %d\n", sum);
    return 0;
}
