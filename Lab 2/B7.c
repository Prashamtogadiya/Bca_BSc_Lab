#include <stdio.h>

int main() {
    int n, i = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    //modulo pending
    while (i <= n) {
        printf("%d ", i);
        i += 2;
    }
    printf("\n");
    return 0;
}
