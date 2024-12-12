#include <stdio.h>

int main() {
    int start, end;
    printf("Enter the start and end values: ");
    scanf("%d %d", &start, &end);

    int i = start+1;
    do {
        if (i % 2 == 0 && i % 4 != 0) {
            printf("%d ", i);
        }
        i++;
    } while (i <= end);
    printf("\n");
    return 0;
}
