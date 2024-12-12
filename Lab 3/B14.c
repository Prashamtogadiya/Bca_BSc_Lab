#include <stdio.h>

int main() {
    int n, i = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    do {
        printf("%d ", i);
        i += 2;
    } while (i <= n);
    printf("\n");
    return 0;
}
