#include <stdio.h>

int main() {
    int n, i = 1;
    double sum = 0.0;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    while (i <= n) {
        sum += 1.0 / i;
        i++;
    }

    printf("Sum of series: %.2f\n", sum);
    return 0;
}
