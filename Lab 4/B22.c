#include <stdio.h>

int main() {
    int start, end;
    printf("Enter the start and end values: ");
    scanf("%d %d", &start, &end);

    for (int i = start; i <= end; i++) {
        if (i % 2 == 0 && i % 4 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
