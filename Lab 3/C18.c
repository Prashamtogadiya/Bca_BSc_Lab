#include <stdio.h>

int main() {
    int n, i = 1;
    double sum = 0.0;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    do {
        sum += 1.0 / i;
        i++;
    } while (i <= n);

    printf("Sum of series: %.2f\n", sum);
    return 0;
}
