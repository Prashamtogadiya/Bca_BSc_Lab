#include <stdio.h>

int main() {
    int n, sum = 0, i = 1;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    while (i <= n) {
        sum += i * i;
        i++;
    }

    printf("Sum of series: %d\n", sum);
    return 0;
}
