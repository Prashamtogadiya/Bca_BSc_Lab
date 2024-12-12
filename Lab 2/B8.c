#include <stdio.h>

int main() {
    int start, end;
    printf("Enter the start and end values: ");
    scanf("%d %d", &start, &end);
//st >end
    int i = start+1;
    while (i <= end) {
        if (i % 2 == 0 && i % 4 != 0) {
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
    return 0;
}
